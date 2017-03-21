#include <stdio.h>

int main(){

    int choice = 100;

    while(choice != 0){

        printf("\n 1. Factorial\n 2. Prime\n 3. Odd/Even\n 4. Exit\n?");
        scanf("%d", &choice);

        switch(choice){

        case 1:
           {
               long long fact = 1, number = 0;
                scanf("%lld", &number);

                while(number > 1){
                    fact *= number--;
                }

                printf("Factorial: %lld", fact);
            }
            break;

        case 2:
            {
                int number = 0;
                scanf("%d", number);

                int primes[301];

                for(int i = 1; i <= 300; i++) primes[i] = 1;

                for(int i = 2; i <= 300; i++){

                    for(int j = i*2; j <= 300; j++){
                        if(j % i == 0) primes[j] = 0;
                    }

                }

                if(primes[number] == 1) printf("The number you entered is prime.\n");
                else printf("The number you entered is not prime.\n");

            }
            break;

        case 3:
            {
                int number;

                scanf("%d", &number);

                printf("The number you entered was %s",
                       number%2 == 0?"even":"odd"
                );
            }
            break;
        case 4:
            choice = 0;
            break;
        default:
            printf("\n Invalid Input\n");

        }

    }



return 0;
}
