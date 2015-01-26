#include <stdio.h>

int factorial(int x)
{
    int f = 1;
    while(x > 0)
    {
        f = f * x;
        x--;
    }
    return(f);
}


int main(){

    int number;
    scanf("%d", &number );

    printf("%d", factorial(number));

return 0;
}
