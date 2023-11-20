#include <stdio.h>

typedef enum
{
    FIND,
    READ,
    SKIP
} State;

int separator(char s) {
    char *m = " \t,\n";
    for (int i = 0; i < 4; i++) {
        if (s == m[i]) return 1;
    }
    return 0;
}

int sonorous(char s) {
    char *m = "бвгджзлмнрйБВГДЖЗЛМНРЙ";
    for (int i = 0; i < 12; i++) {
        if (s == m[i]) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int counter = 0;

    char fcache, scache;
    int chr;
    int flag = 0;

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
                    if (sonorous(chr) && !flag) {
                        flag = 1;
                    } else if (sonorous(chr) && flag) {
                        state = SKIP;
                        flag = 0;
                    } else {
                        state = READ;
                        flag = 0;
                    }
                }
            }
            break;

            case READ:
            {
                if (separator(chr)) {
                    counter++;
                    state = FIND;
                } else if (sonorous(chr) && !flag) {
                    flag = 1;
                } else if (sonorous(chr) && flag) {
                    flag = 0;
                    state = SKIP;
                } else {
                    flag = 0;
                }
            }
        }
    }

    if (state == READ) counter++;

    if (counter) {
        printf("\nThere are words in which all consonants are deaf. The number of such words: %d.", counter);
    } else {
        printf("\nThere are no words in which all consonants are deaf.");
    }
    return 0;
}
