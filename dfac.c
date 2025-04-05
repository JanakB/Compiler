#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

enum State {
    START_STATE,
    USERNAME_STATE,
    AT_STATE,
    DOMAIN_STATE,
    DOT_STATE,
    TOP_LEVEL_DOMAIN_STATE,
    REJECT_STATE
};

bool is_valid_gmail(char* input) {
    enum State state = START_STATE;
    char* p = input;

    while (*p != '\0') {
        switch (state) {
            case START_STATE:
            case USERNAME_STATE:
                if (isalnum(*p) || *p == '_' || *p == '-') {
                    state = USERNAME_STATE;
                } else if (*p == '@') {
                    state = AT_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case AT_STATE:
                if (isalpha(*p)) {
                    state = DOMAIN_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case DOMAIN_STATE:
                if (isalnum(*p) || *p == '-') {
                    state = DOMAIN_STATE;
                } else if (*p == '.') {
                    state = DOT_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case DOT_STATE:
                if (isalpha(*p)) {
                    state = TOP_LEVEL_DOMAIN_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case TOP_LEVEL_DOMAIN_STATE:
                if (isalpha(*p)) {
                    state = TOP_LEVEL_DOMAIN_STATE;
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

    return state == TOP_LEVEL_DOMAIN_STATE;
}

int main() {
    char input[50];

    printf("Enter Gmail ID: ");
    scanf("%s", input);

    if (is_valid_gmail(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}