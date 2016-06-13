#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/in.h>
#include <unistd.h>
#include <linux/if_ether.h>
int main(int argc,char **argv)
{
	int sock,n;
	char buffer[2048];
	unsigned char *iphead, *ethhead;
	struct ifreq ethreq;
	int no=0; //����ԭʼ�׽��ַ�ʽΪ�������е����ݰ�
	if((sock=socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP)))<0)
	{
		perror("\nԭʼ�׽��ֽ���ʧ��\n");
		exit(1);
	} //��������������ʽΪ����ģʽ��SIOCGIFFLAGS�����ʾ��Ҫ��ȡ�ӿڱ�־
	strncpy(ethreq.ifr_name,"eth0",IFNAMSIZ);
	//Interface Name size
	if(ioctl(sock,SIOCGIFFLAGS,&ethreq)==-1)
	{
		perror("\n���û��ӹ���ģʽʧ��\n");
		close(sock);
		exit(1);
	}
	//��ʼ�������ݲ����м򵥷���
	while(1){
		n=recvfrom(sock,buffer,2048,0,NULL,NULL);
		no++;
		printf("\n************%d packet %d bytes ************\n",no,n);
		//�����Ƿ������������������̫֡��14����IP��20����TCP/UDP��8����ͷ
		if(n<42)
		{
			perror("recvfrom():");
			exit(0);
		}
		ethhead=buffer;
		printf("Dest MAC address:%02x:%02x:%02x:%02x:%02x:%02x\n",
			ethhead[0],ethhead[1],ethhead[2],ethhead[3],ethhead[4],ethhead[5]);
		printf("Source MAC address:%02x:%02x:%02x:%02x:%02x:%02x\n",
			ethhead[6],ethhead[7],ethhead[8],ethhead[9],ethhead[10],ethhead[11]);
		iphead=buffer+14;/*����Ethernet header*/
		if(*iphead==0x45)
		{
			/*Double check for IPv4* and no options present*/
		printf("Source host:%d.%d.%d.%d,",
			iphead[12],iphead[13],iphead[14],iphead[15]);
		printf("Dest host:%d.%d.%d.%d\n",
			iphead[16],iphead[17],iphead[18],iphead[19]);
		printf("Source port:%d,Dest port:%d",
			(iphead[20]<<8)+iphead[21],(iphead[22]<<8)+iphead[23]);
		if(iphead[9]==6)
			printf("TCP\n");
		else if(iphead[9]==17)
			printf("UDP\n");
		else
			printf("protocol id:%d\n", iphead[9]);
		}
	}
}
