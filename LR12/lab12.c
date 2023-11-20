#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *mas = (int*)malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++) {
        mas[i] = i;
    }

    int num;
    scanf("%d", &num);

    while (num) {
        if (mas[num % 10] != -1) mas[num % 10] = -1;
        num /= 10;
    }

    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (mas[i] != -1) {
            if (!flag) {
                flag = 1;
                printf("There are numbers that do not occur even once:\n");
            }
            printf("%d\n", mas[i]);
        }
    }
    if (!flag) {
        printf("There are no numbers that do not occur once.");
    }
    return 0;
}
