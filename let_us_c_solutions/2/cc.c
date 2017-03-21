#include <stdio.h>

int main(){
    int number;

    scanf("%d", &number);

    printf("The year you entered is a %s year",
           number%4 == 0?"leap":"normal"
    );

}
