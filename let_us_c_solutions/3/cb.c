#include <stdio.h>

int main(){

    //using while loop only
    long long fact = 1, number = 0;
    scanf("%lld", &number);

    while(number > 1){
        fact *= number--;
    }

    printf("Factorial: %lld", fact);

    return 0;


}
