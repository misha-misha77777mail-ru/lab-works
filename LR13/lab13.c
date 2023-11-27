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

int deaf(char s) {
    char *m = "пфктшсчщхцПФКТШСЧЩХЦ";
    for (int i = 0; i < 12; i++) {
        if (s == m[i]) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int counter = 0;

    int chr;
    int flag = 0;
    int deaf_flag = 0;

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
                    if (deaf(chr) && !deaf_flag) {
                        deaf_flag = 1;
                    } else if (deaf(chr) && deaf_flag == 1) {
                        deaf_flag = 2;
                    }

                    if (sonorous(chr) && !flag) {
                        flag = 1;
                    } else if (sonorous(chr) && flag) {
                        state = SKIP;
                        flag = 0;
                        deaf_flag = 0;
                    } else {
                        state = READ;
                        flag = 0;
                        if (deaf_flag != 2) deaf_flag = 0;
                    }
                }
            }
            break;

            case READ:
            {
                if (deaf(chr) && !deaf_flag) {
                        deaf_flag = 1;
                } else if (deaf(chr) && deaf_flag == 1) {
                        deaf_flag = 2;
                }

                if (separator(chr) && deaf_flag == 2) {
                    counter++;
                    state = FIND;
                    deaf_flag = 0;
                } else if (sonorous(chr) && !flag) {
                    flag = 1;
                } else if (sonorous(chr) && flag) {
                    flag = 0;
                    state = SKIP;
                    deaf_flag = 0;
                } else {
                    flag = 0;
                    if (deaf_flag != 2) deaf_flag = 0;
                }
            }
        }
    }

    if (state == READ && deaf_flag == 2) counter++;

    if (counter) {
        printf("\nThere are words in which all consonants are deaf. The number of such words: %d.", counter);
    } else {
        printf("\nThere are no words in which all consonants are deaf.");
    }
    return 0;
}
