#include <stdio.h>

int main(){
    float marks[5], sum = 0;

    for(int i = 0; i < 5; i++){
        scanf("%f", &marks[i]);
        if(marks[i] > 100 || marks[i] < 0) printf("Invalid Input\n", i--);
        else sum += marks[i];
    }


    printf("Aggregate: %f\nPercentage: %f \%\n", sum/5, (sum/5));

}
