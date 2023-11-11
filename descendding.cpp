#include<stdio.h>
void main(){
    int number[30];
    int i,j,a,n;
    printf("enter the value of N:\n");
    scanf("%d",&n);
    printf("enter the number:\n");
    for(i=0;i<n;++i)
    scanf("%d",&number[i]);
   for(i=0;i<n;++i)
    {
        for(j=1+1;j<n;++j)
    {
   
        if(number[i]<number[j])
    {
   
    a=number[i];
    number[i]=number[j];
    number[j]=a;
   }
}
}
printf("the number arranged in descending order are given below\n");
for(i=0;i<n;++i)
{
printf("%d\n",number[i]);
}


}

