#include <stdio.h>

enum State {
    START_STATE,
    ZERO_STATE,
    ONE_STATE,
    REJECT_STATE
};

int main() {
    enum State state = START_STATE;
    char input;

    printf("Enter binary string: ");

    while ((input = getchar()) != '\n') {
        switch (state) {
            case START_STATE:
                if (input == '0') {
                    state = ZERO_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case ZERO_STATE:
                if (input == '0') {
                    state = ZERO_STATE;
                } else if (input == '1') {
                    state = ONE_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            case ONE_STATE:
                if (input == '0' || input == '1') {
                    state = ONE_STATE;
                } else {
                    state = REJECT_STATE;
                }
                break;
            default:
                state = REJECT_STATE;
                break;
        }
    }

    if (state == ONE_STATE) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}