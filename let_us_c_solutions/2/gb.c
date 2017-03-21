#include <stdio.h>

int main(){
    char input;
    char *output;

    scanf("%c", &input);

    if(( (int)input >= 0 && (int)input <=     47 ) || ( (int)input >= 58 && (int)input <=64 ) || ( (int)input >= 91 && (int)input <=96 || ( (int)input >= 123 && (int)input <=127 ) ) )
        output = "SPL";
    else if( ( (int)input >= 65 && (int)input <= 90 ) )
        output = "UPR";
    else if( ( (int)input >= 97 && (int)input <= 122 ) )
        output = "LWR";
    else if( ( (int)input >= 48 && (int)input <= 57 ) )
        output = "DIG";
    else
        output = "INV";

    printf("%s", output);

}
