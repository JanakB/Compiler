#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
    FILE* file;
    char line[100];
    char nonTerminals[100];
    char terminals[100];
    char productions[100];
    char startingSymbol[100];

    strcpy(nonTerminals, "");
    strcpy(terminals, "");
    strcpy(productions, "");
    strcpy(startingSymbol, "");

    file = fopen("cfg.txt", "r");

    if (file == NULL) {
        printf("Error reading the file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        char* leftSide = strtok(line, "=");
        char* rightSideProductions = strtok(NULL, "\n");

        strcat(nonTerminals, leftSide);
        strcat(nonTerminals, " ");

        if (strcmp(startingSymbol, "") == 0) {
            strcpy(startingSymbol, leftSide);
        }

        char* production = strtok(rightSideProductions, "|");
        while (production != NULL) {
            strcat(productions, leftSide);
            strcat(productions, " => ");
            strcat(productions, production);
            strcat(productions, ", ");

            for (int i = 0; production[i] != '\0'; i++) {
                if (!isupper(production[i]) && production[i] != ' ' &&
                    strchr(terminals, production[i]) == NULL) {
                    strncat(terminals, &production[i], 1);
                    strcat(terminals, " ");
                }
            }

            production = strtok(NULL, "|");
        }
    }

    // Remove trailing ", " from productions
    if (strlen(productions) >= 2) {
        productions[strlen(productions) - 2] = '\0';
    }

    printf("Set of non-terminals = {%s}\n", nonTerminals);
    printf("Set of terminals = {%s}\n", terminals);
    printf("Set of productions = {%s}\n", productions);
    printf("Starting symbol = {%s}\n", startingSymbol);

    fclose(file);

    return 0;
}
