#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

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
int main()
{	
 pthread_t tid;
 printf("Please enter your number \n");
 
 pthread_create(&tid,NULL,*print_prime,NULL);
 pthread_join(tid,NULL);
 
 // printing the values that are stored in array..
 printf("Printing the prime numbers less than or equal to your input \n");
 int c=0;
 for(c=0;c<=Number;c++)
   if(array[c]==1) {
       printf("%d ",c);
	}
 return 0;
 }
