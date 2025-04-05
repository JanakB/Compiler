#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_valid(char *str,int len){
    //const char *first_letter = str[0];
    if (!(isalpha(*str) || *str =='_')){
        printf("%d", isalpha(*str));
        return 0;
    }
    for(int i =1; i<len; i++){
        if(!(isalnum(str[i]) || str[i]=='_')){
            return 0;
        }
    }
    return 1;
}

void main(int arg, char *argv[]){
    char str[100];
    printf("%s","Enter a variable name: ");
    scanf("%s",str);
    if(is_valid(str,strlen(str))){
        printf("%s \n","Valid String");
    }
    else{
        printf("%s \n","Invalid String");
    }
}