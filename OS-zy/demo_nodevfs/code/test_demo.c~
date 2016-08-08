//test_demo.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

char MAX_LEN=2;
char H = 7, L = 8;
void showbuf(char *buf)
{
	int i,j=0;
	for(i = 0; i < H; i ++)
	{	
		for(j = 0; j < L; j ++)
			printf("%c",(buf[i*L+j]+'A'));
		printf("\n");
	}	
	printf("\n*********************************\n");
}
int main()
{
	H = 4;
	L = 6;
	int fd,i;
	char buf[255];
	buf[0] = H;
	buf[1] = L;
	fd=open("/dev/evan",O_RDWR);
	if(fd<0)
	{
	printf("######nodevfs drivers open failed!!######\n");
		return(-1);
	}
	printf("######nodevfs drivers open success!!######\n");
	printf("write %d bytes data to /dev/evan \n",MAX_LEN);
	printf("%d \n",buf[0]);
	printf("%d \n",buf[1]);
	printf("*********************************************");
	printf("\n");
	//printf("write %d and %d to the /dev/evan\n",buf[0],buf[1]);
	write(fd,buf,MAX_LEN);
	MAX_LEN = buf[0] * buf[1];
	printf("Read %d bytes data from /dev/evan \n",MAX_LEN);
	read(fd,buf,MAX_LEN);
	showbuf(buf);
	ioctl(fd,1,NULL);
	close(fd);
	return 0;
}
