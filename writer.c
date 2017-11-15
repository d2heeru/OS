#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	int fd,nbr;
	char str[100];
	mknod("myfifo67",S_IFIFO|0666,0);
	printf("writing for reader process:\n");
	fd=open("myfifo67",O_WRONLY);
	while(gets(str))
	{
		nbr=write(fd,str,strlen(str));
		printf("writer process write %d byte: %s \n",nbr,str);
	}
	return 0;
}
