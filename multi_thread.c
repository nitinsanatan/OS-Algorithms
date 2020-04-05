#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_THREADS 1

int Number; //creating a global variable. 
int array[]={0}; //global array of prime no

void *print_prime(void *ptr) //function to check the prime no
{
  int  j,check;
  scanf("%d",&Number);
  
  int i=(int)ptr;
  for(i=2;i<=Number;i++){
     check=0;
     for(j=2;j<=i-1;j++)
       {
        if(i%j==0)
          {
           check=1;
           break;
          }
       }

     if(check==0)
     {
       array[i]=1;
     }
  }
}
