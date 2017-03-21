#include <stdio.h>
#include <math.h>

int main(){

    int primes[301];

    for(int i = 1; i <= 300; i++) primes[i] = 1;

    for(int i = 2; i <= 300; i++){

        for(int j = i*2; j <= 300; j++){
            if(j % i == 0) primes[j] = 0;
        }

    }

    for(int i = 1; i <= 300; i++) primes[i] <= 0?:printf("%d\n", primes[i]*i);

    return 0;
}
