#include <stdio.h>

typedef enum
{
    FIND,
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    SKIP
} State;

int separator(char s) {
    char *m = " \t,\n";
    for (int i = 0; i < 4; i++) {
        if (s == m[i]) return 1;
    }
    return 0;
}

int main() {
    int counter = 0;
    int flag = 0;

    char fcache, scache;
    int chr;

    State state = FIND;

    while ((chr = getchar()) != EOF) {
        switch (state) {
            case SKIP:
            {
                if (separator(chr)) state = FIND;
            }
            break;

            case FIND:
            {
                if (!separator(chr)) {
                    state = FIRST;
                    fcache = chr;
                }
            }
            break;

            case FIRST:
            {
                if (((chr == '1' | chr == '0') && fcache == '0') | (chr == '0' && fcache == '1')) {
                    state = SECOND;
                    scache = chr;
                } else if (!separator(chr)) {
                    state = SKIP;
                } else {
                    state = FIND;
                }
            }
            break;

            case SECOND:
            {
                if (chr == '1' && scache == '0' && fcache == '1') {
                    state = SKIP;
                } else if (chr == '0' | chr == '1') {
                    state = THIRD;
                } else if (!separator(chr)) {
                    state = SKIP;
                } else {
                    state = FIND;
                }
            }
            break;

            case THIRD:
            {
                if (chr == '0' | chr == '1') {
                    state = FOURTH;
                } else if (!separator(chr)) {
                    state = SKIP;
                } else {
                    state = FIND;
                }
            }
            break;

            case FOURTH:
            {
               if (chr == '0' | chr == '1') {
                   state = FIRST;
               } else if (separator(chr)) {
                   counter++;
                   state = FIND;
               }
            }
        }
    }

    if (state == FOURTH) counter++;

    printf("\n%d", counter);
    return 0;
}