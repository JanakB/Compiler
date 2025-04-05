#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);
    if (str[0]=='0' && str[strlen(str)-1]=='1'){
        printf("Accepted");
    }
    else{
        printf("Rejected");
    }
    return 0;
} 