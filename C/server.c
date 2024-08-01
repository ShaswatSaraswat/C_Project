#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define SIZE 512
#define PORT 8181

int main()
{
	int s, c;
	socklen_t addrlen;
	struct sockaddr_in srv, cli;
	char buf[SIZE];
	char *data = "httpd v1.0\n";

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		perror("socket()");
		close(s);
		return -1;
	}

	srv.sin_family = AF_INET;
	srv.sin_addr.s_addr = 0;
	srv.sin_port = htons(PORT);

	if (bind(s, (struct sockaddr *)&srv, sizeof(srv)) < 0) {
		perror("bind()");
		close(s);
		return -1;
	}

	if (listen(s, 5) < 0) {
		perror("listen()");
		return -1;
	}

	printf("Listening on 0.0.0.0 : %d\n", PORT);

	addrlen = sizeof(cli);
	c = accept(s, (struct sockaddr *)&cli, &addrlen);
	if (c < 0) {
		perror("accept()");
		close(s);
		return -1;
	}

	printf("Client Connected !!!\n");

	read(c, buf, SIZE);
	write(c, data, strlen(data));

	close(c);
	close(s);
	return 0;

