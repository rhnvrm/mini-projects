#include <stdio.h>

int main(){
    int number;

    scanf("%d", &number);

    printf("The number you entered was %s",
           number%2 == 0?"even":"odd"
    );

}
