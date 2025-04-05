#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

enum State {
    START_STATE,
    IDENTIFIER_STATE,
    REJECT_STATE
};

bool is_valid_variable(char* input) {
    enum State state = START_STATE;
    char* p = input;

    while (*p != '\0') {
        switch (state) {
            case START_STATE:
                if (isalpha(*p) || *p == '_') {
                    state = IDENTIFIER_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case IDENTIFIER_STATE:
                if (isalnum(*p) || *p == '_') {
                    state = IDENTIFIER_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            default:
                state = REJECT_STATE;
                break;
        }
        p++;
    }

    return state == IDENTIFIER_STATE;
}

int main() {
    char input[50];

    printf("Enter variable name: ");
    scanf("%s", input);

    if (is_valid_variable(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}