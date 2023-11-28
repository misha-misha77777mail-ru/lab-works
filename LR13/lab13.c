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
    const unsigned int lu = 1;
    const wchar_t a = L'б';

    const unsigned int sonorous = (
        lu << (L'б' - a) |
        lu << (L'в' - a) |
        lu << (L'г' - a) |
        lu << (L'д' - a) |
        lu << (L'ж' - a) |
        lu << (L'з' - a) |
        lu << (L'л' - a) |
        lu << (L'м' - a) |
        lu << (L'н' - a) |
        lu << (L'р' - a) |
        lu << (L'й' - a)
    );

    const unsigned int deaf = (
        lu << (L'п' - a) |
        lu << (L'ф' - a) |
        lu << (L'к' - a) |
        lu << (L'т' - a) |
        lu << (L'ш' - a) |
        lu << (L'с' - a) |
        lu << (L'ч' - a) |
        lu << (L'щ' - a) |
        lu << (L'х' - a) |
        lu << (L'ц' - a)
    );

    unsigned int word = 0;
    int counter = 0;
    wchar_t chr;

    while ((chr = getchar()) != EOF) {
        if (separator(chr) && word) {
            if (((word & sonorous) <= 1) && (word & deaf)) {
                counter++;
            }
            word = 0;
        } else {
            word = word | lu << (towlower(chr) - a);
        }
    }

    if (((word & sonorous) <= 1) && (word & deaf)) counter++;

    if (counter) {
        printf("\nThere are words in which all consonants are deaf.\n");
        printf("The number of such words: %d.", counter);
    } else {
        printf("\nThere are no words in which all consonants are deaf.");
    }

    return 0;
}
