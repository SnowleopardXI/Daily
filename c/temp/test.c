#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <wiringPi.h>
#include <softPwm.h>

#define BUFSIZE 512

int PWMA = 1;
int AIN2 = 2;
int AIN1 = 3;

int PWMB = 4;
int BIN2 = 5;
int BIN1 = 6;

void  t_up(unsigned int speed,unsigned int t_time)
{
	 digitalWrite(AIN2,0);
	 digitalWrite(AIN1,1);
	 softPwmWrite(PWMA,speed);
	 
	 
	 digitalWrite(BIN2,0);
	 digitalWrite(BIN1,1);
	 softPwmWrite(PWMB,speed);
	 delay(t_time);
}

void t_stop(unsigned int t_time)
{
	 digitalWrite(AIN2,0);
	 digitalWrite(AIN1,0);
	 softPwmWrite(PWMA,0);
	 
	 digitalWrite(BIN2,0);
	 digitalWrite(BIN1,0);
	 softPwmWrite(PWMB,0);
	 delay(t_time);	
}

void t_down(unsigned int speed,unsigned int t_time)
{
	 digitalWrite(AIN2,1);
	 digitalWrite(AIN1,0);
	 softPwmWrite(PWMA,speed);
	 
	 digitalWrite(BIN2,1);
	 digitalWrite(BIN1,0);
	 softPwmWrite(PWMB,speed);
	 delay(t_time);	
}

void t_left(unsigned int speed,unsigned int t_time)
{
	 digitalWrite(AIN2,1);
	 digitalWrite(AIN1,0);
	 softPwmWrite(PWMA,speed);
	 
	 digitalWrite(BIN2,0);
	 digitalWrite(BIN1,1);
	 softPwmWrite(PWMB,speed);
	 delay(t_time);	
}

void t_right(unsigned int speed,unsigned int t_time)
{
	 digitalWrite(AIN2,0);
	 digitalWrite(AIN1,1);
	 softPwmWrite(PWMA,speed);
	 
	 digitalWrite(BIN2,1);
	 digitalWrite(BIN1,0);
	 softPwmWrite(PWMB,speed);
	 delay(t_time);	
}

typedef struct CLIENT {
	int fd;
	struct sockaddr_in addr;
}CLIENT;

int main(int argc, char *argv[])
{
    int sockfd;
    int listenfd;
    int connectfd;

    int ret;
    int maxfd=-1;
    struct timeval tv;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    socklen_t len;
    int portnumber;

    char buf[BUFSIZE];

    int z,i,maxi = -1;
    fd_set rset,allset;

    CLIENT client[FD_SETSIZE];

    /*RPI*/
    wiri