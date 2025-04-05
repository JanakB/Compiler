#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

enum State {
    START_STATE,
    FIRST_DIGIT_STATE,
    SECOND_DIGIT_STATE,
    THIRD_DIGIT_STATE,
    FOURTH_DIGIT_STATE,
    REJECT_STATE
};

bool is_valid_prepaid_ntc(char* input) {
    enum State state = START_STATE;
    char* p = input;

    while (*p != '\0') {
        switch (state) {
            case START_STATE:
                if (*p == '9') {
                    state = FIRST_DIGIT_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case FIRST_DIGIT_STATE:
            case THIRD_DIGIT_STATE:
                if (isdigit(*p)) {
                    state++;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case SECOND_DIGIT_STATE:
                if (*p == '8' || *p == '9') {
                    state++;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case FOURTH_DIGIT_STATE:
                if (*p == '0') {
                    state++;
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

    return state == FOURTH_DIGIT_STATE + 1;
}

int main() {
    char input[50];

    printf("Enter prepaid NTC number: ");
    scanf("%s", input);

    if (is_valid_prepaid_ntc(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}