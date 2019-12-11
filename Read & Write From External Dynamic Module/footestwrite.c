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
   scanf("%s",f);#include<unistd.h>
2
#include<sys/types.h>
3
#include<linux/fcntl.h>
4
#include<stdio.h>
5
#include<stdlib.h>
6
​
7
int main()
8
{
9
​
10
   int fd,ret,buf[1024];
11
​
12
   fd = open("/sys/kernel/kobject_example/foo",O_RDWR);
13
   if(fd<0){
14
           perror("error in opening");
15
           exit(1);
16
   }
17
​
18
   printf("value of fd is %d\n", fd); 
19
​
20
​
21
  while(1){
22
   char f[10];
23
   scanf("%s",f);
24
   ret=printf("%s",f);
25
   printf("the no. characters read is %d\n", ret);
26
   if(ret>0) { write(fd,f,ret); } 
27
        break;
28#include<unistd.h>
2
#include<sys/types.h>
3
#include<linux/fcntl.h>
4
#include<stdio.h>
5
#include<stdlib.h>
6
​
7
int main()
8
{
9
​
10
   int fd,ret,buf[1024];
11
​
12
   fd = open("/sys/kernel/kobject_example/foo",O_RDWR);
13
   if(fd<0){
14
           perror("error in opening");
15
           exit(1);
16
   }
17
​
18
   printf("value of fd is %d\n", fd); 
19
​
20
​
21
  while(1){
22
   char f[10];
23
   scanf("%s",f);
24
   ret=printf("%s",f);
25
   printf("the no. characters read is %d\n", ret);
26
   if(ret>0) { write(fd,f,ret); } 
27
        break;
28
   }
29
 // lseek(fd,0,SEEK_SET);
30
/*
31
   ret = read(fd,buf,4096);     if(ret<0) { perror("error in read"); exit(6); }
32
   if(ret==0) exit(0) ;  //end of file - no more data
33
   
34
   printf("the no. characters returned is %d\n", ret);
35
​
36
   if(ret>0) { write(STDOUT_FILENO,buf,ret); } 
37
​
38
*/   
39
   exit(0);
40
​
41
}
42

   }
29
 // lseek(fd,0,SEEK_SET);
30
/*
31
   ret = read(fd,buf,4096);     if(ret<0) { perror("error in read"); exit(6); }
32
   if(ret==0) exit(0) ;  //end of file - no more data
33
   
34
   printf("the no. characters returned is %d\n", ret);
35
​
36
   if(ret>0) { write(STDOUT_FILENO,buf,ret); } 
37
​
38
*/   
39
   exit(0);
40
​
41
}
42

   ret=printf("%s",f);
   printf("\nthe no. characters read is %d\n", ret);
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
