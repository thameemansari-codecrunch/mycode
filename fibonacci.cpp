#include<stdio.h>
int main(){
    int count,n,t1=0,t2=1,display=0;
    printf("enter number of terms:");
    scanf("%d",&n);
    printf("fibonacci series\n");
     printf("the given term is %d,\n",n);
    printf("fibonacci series:\n%d\n%d\n",t1,t2);
    count=2;
    while(count<n)
    {
        display=t1+t2;
        t1=t2;
        t2=display;
        ++count;
        printf("%d\n",display);
       
    }
       
        return 0;
    }
