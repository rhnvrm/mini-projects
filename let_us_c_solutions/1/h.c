#include <stdio.h>

int main(){
    //To input a number and find the sum of it's first and last digits

    char number[5];

    scanf("%s", &number);

    for(int i = 4; i >= 0; i--) printf("%c", number[i]);

}
