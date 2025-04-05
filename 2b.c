#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char string[100];
    int flag = 1;
    printf("Enter a string with alphabets between a and b: ");
    scanf("%s", string);

    if(strlen(string)!=2){
        printf("Invlaid string input \n");
        return 0;
    }
    
    if(((string[0]!='a') || (string[0]!='b')) && ((string[0]!='a') || (string[1]!='b'))){
      printf("Invalid string input\n");
      return 0;
    }

    printf("Valid string input\n");
    return 0;
}