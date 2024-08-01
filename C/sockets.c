/* socket.c */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#define IP "142.250.192.3"
#define SIZE 512
#define PORT 80 /* http */

int main()
{
	char buf[SIZE];
	char *data;
	data="HEAD / HTTP/1.0\r\n\r\n";
	int s;
	struct sockaddr_in sock;
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s<0)
	{
		printf("Socket Error !!\n");
		return -1;
	}
	sock.sin_addr.s_addr = inet_addr(IP);
	sock.sin_port = htons(PORT);
	sock.sin_family=AF_INET;
	if(connect(s,(const struct sockaddr *)&sock,sizeof(const struct sockaddr_in))!=0){
		printf("connect() error\n");
		close(s);
		return -1;
	}
write(s,data,strlen(data));
memset(buf,0,SIZE-1);
read(s,buf,SIZE-1);
close(s);
printf("\n%s\n",buf);
return 0;
}
