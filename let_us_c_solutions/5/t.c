#include<stdio.h>
int main(){
float a,b,c;
char i;

scanf("%f %f %s",&a,&b,&i);

if (i=='a')
    c=a+b;
else if(i=='s')
    c=a-b;
else if(i=='m')
    c=a*b;
else if(i=='d')
    c=a/b;
printf("%f",c);

return 0;
}
