#include <stdio.h>

int main(){
    float d_km;

    scanf("%f", &d_km);

    printf("Meters: %f\nCentimeters: %f\n", d_km * 1000, d_km * 100000);

}
