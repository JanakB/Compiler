#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char string[100];
    int flag = 1;
    printf("Enter a string with alphabets between a and b: ");
    scanf("%s", string);
    if(strlen(string)==0){
        printf("Invlaid string input \n");
        return 0;
    }

    for (int i= 0; i < strlen(string)-1; i++) {
        //printf("%c", *(string+i));
        if((string[i] =='b') || (string[i] == 'a')){
            continue;
        }
        else{
            printf("Invalid string input \n");
            return 0;
        }
    }

    if(string[strlen(string)-1]!='a'){
        printf("Invalid string input \n");
        return 0;
    }

    printf("Valid string input\n");
    return 0;
}