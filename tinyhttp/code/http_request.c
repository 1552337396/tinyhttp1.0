#include "http_request.h"
void request_accept(int fd)
{
	char buf[10240];
	if(read(fd, buf, 10240) <= 0)
	{
		//printf("%d read fail\n", fd);
		close(fd);
		return ;
	}
	//int flag = fcntl(fd, F_GETFL, 0);
	//fcntl(fd, F_SETFL, flag | O_NONBLOCK);
	//printf("%s\n\n\n", buf);
	char url[50] = "\0", method[10] = "\0";
	int i = 0,j = 0;
	while(buf[i] == ' ' && buf[i] != '\0')
	{
		i++;
	}
	while(buf[i] != ' ' && buf[i] != '\0' && j < sizeof(method))
	{
		method[j] = buf[i];
		i++;
		j++;
	}
	//printf("method :%s\n\n\n", method);
	if(strcmp(method, "GET") != 0)
	{
		request_stat(fd, 405);
		close(fd);
		return ;
	}
	while(buf[i] == ' ' && buf[i] != '\0')
	{
		i++;
	}
	j = 0;
	while(buf[i] != ' ' && buf[i] != '\0' && j < sizeof(url))
	{
		url[j] = buf[i];
		i ++;
		j ++;
	}
	char path[100] = "../page";
	strcat(path, url);
	//printf("path :%s\n\n\n", path);
	int l = strlen(path);
	if(path[l - 1] == '/')
		strcat(path, "index.html");
	Sendfile(fd, path);
	close(fd);
	return ;
}
int Sendfile(int fd,char *path)
{
	struct stat st;
	int l = strlen(path);
	if(stat(path, &st) == 0)
	{
		if(S_ISREG(st.st_mode))
		{
			int filefd  = open(path, O_RDONLY);
			request_stat(fd, 200);
			if(strcmp(&path[l -4], ".jpg") == 0)
			{
				request_header(fd, 2);
			}
			else 
			{
				request_header(fd, 1);
			}
			sendfile(fd, filefd, NULL, st.st_size);
			close(filefd);
			return 0;
		}
		else if(S_ISDIR(st.st_mode))
		{
			strcat(path, "/index.html");
			if(stat(path, &st) == 0)
			{
				int filefd = open(path, O_RDONLY);
				request_stat(fd, 200);
				request_header(fd, 1);
				sendfile(fd, filefd, NULL, st.st_size);
				close(filefd);
				return 0;
			}
			else 
			{
				request_stat(fd, 404);
				request_header(fd, 1);
				return -1;
			}
		}
	}
	else 
	{
		request_stat(fd, 404);
		request_header(fd, 1);
		return -1;
	}
}
void request_stat(int fd, int statcode)
{
	char line[100];
	if(statcode == 200)
	{
		strcpy(line, line200);//send 200
	}
	else if(statcode == 404)
	{
		strcpy(line, line404);//send 404
	}
	else if(statcode == 405)
	{
		strcpy(line, line405);//send 405
	}
	else if(statcode == 500)
	{
		strcpy(line, line500);//send 500
	}
	write(fd, line, strlen(line));
	return ;
}
void request_header(int fd, int statcode)
{
	char header[500];
	if(statcode == 1)
	{
		strcpy(header, htmlheader);
	}
	else if(statcode == 2)
	{
		strcpy(header, imgheader);
	}
	write(fd, header, strlen(header));
	return ;
}
