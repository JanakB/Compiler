#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    printf("Enter e-mail: ");
    scanf("%s",str);
    int len = strlen(str);
    const char *portion = &str[len-10];
    if(strcmp( portion,"@gmail.com") == 0){
        printf("Accepted");
    }
    else{
        printf("Rejected");
    }
    return 0;
}