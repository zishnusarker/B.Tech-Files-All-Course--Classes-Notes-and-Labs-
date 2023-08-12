#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

int tempterm;
tempterm=fork();
if(tempterm==0)
{
printf("Chid\n");
printf("PID: %d\n",getpid());
}
if(tempterm>0)
{
 printf("Parent\n");
printf("PID: %d\n",getpid());
}
return 0;
}
