#include <stdio.h>

int main(){

    //using while loop only
    int emp = 10;
    while(emp--){

        int time = 0;

        printf("Hours by employee #%d: ", 10 - emp);
        scanf("%d", &time);
        printf("Calculated overtime: Rs. %d\n",

            time > 40 ? (time - 40) * 12 : 0

        );

    }

    return 0;


}
