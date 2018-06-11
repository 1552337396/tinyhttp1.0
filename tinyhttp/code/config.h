#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define default_port 8888
#define default_thread_num 4
#define default_listen_num 10240

struct http_conf
{
	int port;
	int thread_num;
	int listen_num;
};

void init_http_conf(struct http_conf*);
void default_init_http_conf(struct http_conf*);

#endif
