#ifndef _HTTP_REQUEST_H_
#define _HTTP_REQUEST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/sendfile.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#define line200 "HTTP/1.0 200 OK\r\n"
#define line404 "HTTP/1.0 404 NOT FOUND\r\n"
#define line405 "HTTP/1.0 405 NOT ALLOW\r\n"
#define line500 "HTTP/1.0 500 SERVER ERROR\r\n"
#define imgheader "Server: httpd\r\nContent-Type: image/jpeg\r\n\r\n"
#define htmlheader "Server: httpd\r\nContent-Type: text/html\r\n\r\n"
void request_accept(int);
int Sendfile(int ,char *);
void request_stat(int, int);
void request_header(int ,int);


#endif
