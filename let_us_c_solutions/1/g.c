#include <stdio.h>

int main(){
    //To input a number and find the sum of it's first and last digits

    char number[5];
    int sum = 0;

    scanf("%s", &number);

    for(int i = 0; i < 5; i++) sum+= (int)number[i];

    printf("%d", sum - 5*(int)'0');
}
