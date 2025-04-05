#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int arg, char *argv){
    char *number;
    char *prefix = "98";
    printf("%s","Enter a phone number: ");
    scanf("%s",number);
    printf("%c",strstr(number, "98"));
    if((strncmp(prefix, number, strlen(prefix)) == 0) && strlen(number) == 10){
        printf("%s","Valid Number");
    }
    else{
        printf("%s","Invalid Number.");
    }
}