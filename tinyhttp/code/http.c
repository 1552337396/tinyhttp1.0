#include "http.h"
#include <signal.h>
int Startup(struct http_conf config)
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1)
	{
		printf("socket fail\n");
		return -1;
	}
	int op = 1;
	struct timeval timeout = {1, 0};
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (void *)&op, sizeof(op));
	setsockopt(fd, SOL_SOCKET, TCP_NODELAY, (void *)&op, sizeof(op));
	setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
	struct sockaddr_in ADDR;
	memset(&ADDR, 0, sizeof(ADDR));
	ADDR.sin_family = AF_INET;
	ADDR.sin_port = htons(config.port);
	ADDR.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(fd, (struct sockaddr *)&ADDR, sizeof(ADDR)) == -1)
	{
		printf("bind fail\n");
		return -1;
	}
	if(listen(fd, config.listen_num) == -1)
	{
		printf("listen fail\n");
		return -1;
	}
	else 
	{
		printf("listen num:%d\n", config.listen_num);
	}
	return fd;
}
int main()
{
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGPIPE);
	sigprocmask(SIG_BLOCK, &sigset, NULL);
	int pid = getpid();
	printf("pid:%d\n", pid);
	struct http_conf config;
	init_http_conf(&config);
	int fd = Startup(config);
	struct threadpool *pool = threadpool_init(config.thread_num);
	if(pool == NULL)
	{
		printf("pool init fail\n");
		return -1;
	}
	int num = 0;
	while(1)
	{
		int client = accept(fd, NULL, 0);
		if(client == -1)
			continue;
		//printf("num :%d\n", ++num);
		//request_accept(client);
		threadpool_add_job(pool, request_accept, client);
	}
	return 0;
}
