#include<unistd.h>
#include<sys/types.h>
#include<linux/fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{

   int fd,ret,buf[1024];

   fd = open("/sys/kernel/kobject_example/foo",O_RDWR);
   if(fd<0){
           perror("error in opening");
           exit(1);
   }

   printf("value of fd is %d\n", fd); 


  while(1){
   char f[10];
   scanf("%s",f);
   ret=printf("%s",f);
   printf("the no. characters read is %d\n", ret);
   if(ret>0) { write(fd,f,ret); } 
	break;
   }
 // lseek(fd,0,SEEK_SET);
/*
   ret = read(fd,buf,4096);	if(ret<0) { perror("error in read"); exit(6); }
   if(ret==0) exit(0) ;  //end of file - no more data
   
   printf("the no. characters returned is %d\n", ret);

   if(ret>0) { write(STDOUT_FILENO,buf,ret); } 

*/   
   exit(0);

}
