#include <stdio.h>

int main(){
    float l,b,r;

    scanf("%f %f %f", &l, &b, &r);

    printf("Rectangle\nPerimeter: %f, Area: %f\nCircle\nArea: %f, Circum: %f\n",
           2*(l+b),
           l*b,
           r*r*3.14,
           2*3.14*r
    );

}
