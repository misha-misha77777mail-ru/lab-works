#include <stdio.h>
#include <stddef.h>
#include <wctype.h>

int separator(char s) {
    char *m = " \t,\n";
    for (int i = 0; i < 4; i++) {
        if (s == m[i]) return 1;
    }
    return 0;
}

int main(void) {
    const unsigned int lu = 1, a = 1073U;
    wchar_t *s = L"бвгджзлмнрй", *d = L"пфктшсчщхц";
    unsigned int sonorous = 0, deaf = 0;

    for (int i = 0; i < 11; i++) {
        sonorous = sonorous | lu << (s[i] - a);
    }
    for (int i = 0; i < 10; i++) {
        deaf = deaf | lu << (d[i] - a);
    }

    unsigned int word = 0;
    int counter = 0;
    wchar_t chr;

    while ((chr = getchar()) != EOF) {
        if (separator(chr) && word) {
            if (!((word & sonorous) >> 1) && (word & deaf)) {
                counter++;
            }
            word = 0;
        } else {
            word = word | lu << (towlower(chr) - a);
        }
    }

    if (!((word & sonorous) >> 1) && (word & deaf)) counter++;

    if (counter) {
        printf("\nThere are words in which all consonants are deaf.\n");
        printf("The number of such words: %d.", counter);
    } else {
        printf("\nThere are no words in which all consonants are deaf.");
    }

    return 0;
}
