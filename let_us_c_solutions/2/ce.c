#include <stdio.h>

int main(){
    int number;

    scanf("%d", &number);

    //check whether the given number is a palindrome

    int r_number = 0;
    int t = number;
    while(t){

        r_number *= 10;
        r_number += t % 10;
        t /= 10;

    }

    printf("%d", r_number);

}
