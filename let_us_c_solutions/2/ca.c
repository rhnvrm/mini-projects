#include <stdio.h>

int main(){
    float cp, sp;

    scanf("%f %f", &cp, &sp);

    printf("You made: %s of %f Rupees",
           cp>sp?"loss":"profit",
           sp - cp
    );

}
