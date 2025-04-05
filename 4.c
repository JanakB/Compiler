#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataType{
    char type[16];
    long size;
};

struct dataType dataTypes[] = {{"int",4}, {"char",1}, {"short",2}, {"long",8}, {"float",4}, {"double",8}};


struct Symbols{
    char name[128];
    struct dataType data_type;
    char value[128];
    char address[64];
};

struct dataType getDataType(char type[]){
    int length = sizeof(dataTypes)/sizeof(dataTypes[0]);
    for(int i=0;i<length;i++){
        if(strcmp(type, dataTypes[i].type)==0){
            return dataTypes[i];
        }
        else{
            continue;
        }
    } 
    exit(1);
}

int main(){
    struct Symbols symbols[100];
    char type[16];
    char name[128];
    int length;

    printf("Enter the number of symbols to be used: ");
    scanf("%d", &length);
    printf("\n");
     
    for(int i=0; i<length; i++){
        printf("\nEnter the dataType: ");
        scanf("%s", type);
        struct dataType temp =  getDataType(type);
        symbols[i].data_type = temp;

        printf("Enter the name of variable: ");
        scanf("%s", symbols[i].name);

        printf("Enter the value of variable: ");
        scanf("%s", symbols[i].value);

        int *allocatedAddress = (int *)malloc(temp.size);
        sprintf(symbols[i].address, "%p", (void *)allocatedAddress);
    }

    printf("\nName \t DataType \t\t value \t\t address\n");
    for(int i=0; i<length;i++){
        printf("%s \t %s \t\t\t %s \t\t %s \n", symbols[i].name, symbols[i].data_type.type, symbols[i].value, symbols[i].address); 
    }

    return 0;
}