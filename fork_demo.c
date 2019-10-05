#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int main(){

int ret,status;
int i=0;
while(i++<5){

	ret =fork();
if(ret<0){
perror("error in fork ");
printf("the final value of i is %u\n",i);
exit(1);
         }

if(ret>0){
printf("I am in Parent Process context\n");
printf("in parent...ppid is %lu...and pid is %lu\n ",getppid(),getpid());

continue;
}

if(ret==0){
printf("I am in  child process context\n");
printf("in child ...ppid is %lu...and pid is %lu\n", getppid(),getpid());


if(i==1||i==2){
	printf("i=%d",i);
	exit(0);
              }
if(i==3){
	printf("i=%d",i);
	exit(1);
                 

}
while(1);

break;

}
}

if(ret>0){
while(1){
	ret=waitpid(-1,&status,0);
	if(ret>0){
	
	if(WIFEXITED(status)){
	
        	if(WEXITSTATUS(status)){
    		printf("normal and sucessfull and pid=%d \n",ret);
	}
	
		else{
		printf("normal and unsucessfull and pid =%d \n",ret);
	
	
	}
	
	}
	
	else{
	printf("abnormal and unsucessfully\n ");
	}
        }
if(ret<0){
printf("Parent has cleared all the child processes");
	exit(0);
}




}



}
return 0;
}

