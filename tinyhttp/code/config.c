#include "config.h"

void init_http_conf(struct http_conf *conf)
{
	default_init_http_conf(conf);
	FILE *fd = fopen("../etc/config", "r");
	if(fd == NULL)
	{
		perror("open config error, use default config\n");
		return ;
	}
	char buf[100], key[30], value[30];
	while(fgets(buf, 100, fd) != NULL)
	{
		sscanf(buf, "%s %s", key, value);
		if(strcmp(key, "port") == 0)
		{
			conf -> port = atoi(value);
		}
		else if(strcmp(key, "thread_num") == 0)
		{
			conf -> thread_num = atoi(value);
		}
		else if(strcmp(key, "listen_num") == 0)
		{
			conf -> listen_num = atoi(value);
		}
	}
	fclose(fd);
	return ;
}
void default_init_http_conf(struct http_conf *conf)
{
	conf -> port = default_port;
	conf -> thread_num = default_thread_num;
	conf -> listen_num = default_listen_num;
	return ;
}
