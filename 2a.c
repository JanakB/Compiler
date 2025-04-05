#include <stdio.h>
#include <stdbool.h>

enum State {
    STATE_0,
    STATE_1,
    STATE_2,
    STATE_3,
    STATE_4,
    STATE_5,
    STATE_6,
    STATE_7
};

bool is_accepted(char* input) {
    enum State state = STATE_0;
    char* p = input;

    while (*p != '\0') {
        switch (state) {
            case STATE_0:
                if (*p == 'a') {
                    state = STATE_1;
                } else if (*p == 'b') {
                    state = STATE_6;
                } else {
                    return false;
                }
                break;
            case STATE_1:
                if (*p == 'a') {
                    state = STATE_2;
                } else if (*p == 'b') {
                    state = STATE_3;
                } else {
                    return false;
                }
                break;
            case STATE_2:
                if (*p == 'a' || *p == 'b') {
                    state = STATE_3;
                } else {
                    return false;
                }
                break;
            case STATE_3:
                if (*p == 'a') {
                    state = STATE_4;
                } else if (*p == 'b') {
                    state = STATE_5;
                } else {
                    return false;
                }
                break;
            case STATE_4:
            case STATE_5:
            case STATE_6:
                if (*p == 'a' || *p == 'b') {
                    state = STATE_7;
                } else {
                    return false;
                }
                break;
            default:
                return false;
        }
        p++;
    }

    return state == STATE_4 || state == STATE_7;
}

int main() {
    char input[50];

    printf("Enter a string: ");
    scanf("%s", input);

    if (is_accepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}



