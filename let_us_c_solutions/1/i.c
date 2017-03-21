#include <stdio.h>

int main(){
    //To input a number and find the sum of it's first and last digits

    char number[5];

    scanf("%s", &number);

    printf("%c + %c = %d", number[0], number[3], (int)number[0] + (int)number[3] -2*(int)'0' );

}
