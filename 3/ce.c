#include <stdio.h>
#include <math.h>

int main(){

    //Armstrong Numbers

    for(int i = 1; i < 501; i++){

        int t = i;

        int sum = 0;
        while(t){
            sum += pow(t%10, 3);
            t/=10;
        }

        if(sum == i) printf("%d\t", i);
    }


    return 0;


}
