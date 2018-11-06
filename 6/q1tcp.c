#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
	int n;
	unsigned int m = sizeof(n);
	int fdsocket = socket(AF_INET, SOCK_DGRAM, 0);
	getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&n, &m);
	printf("Send buffer: %d\n", n);
	getsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(void *)&n, &m);
	printf("Receive buffer: %d\n", n);
	long k;
	unsigned int l = sizeof(k);
	int r = setsockopt(fdsocket, SOL_SOCKET, SO_SNDBUF,(void *)&k, l);
	getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&n, &m);
	printf("New size: %d\n", n);
	printf("For a value greater than the original value : %d\n", r);
	short p;
	unsigned int q = sizeof(p);
	int s = setsockopt(fdsocket, SOL_SOCKET, SO_SNDBUF,(void *)&p, q);
	printf("For a value smaller than the original value : %d\n", s);
}
