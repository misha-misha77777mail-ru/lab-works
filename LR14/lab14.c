#include <stdio.h>

int main(void) {
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);

    int matrix[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Entered matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }

    for (int count = 0; count < size; count++) {
        if (count % 2 == 0) {
            for (int i = 0; i <= count; i++) {
                for (int j = 0; j <= count; j++) {
                    if (i + j == count) {
                        printf("%d ", matrix[i][j]);
                    }
                }
            }
        } else {
            for (int i = count; i >= 0; i--) {
                for (int j = count; j >= 0; j--) {
                    if (i + j == count) {
                        printf("%d ", matrix[i][j]);
                    }
                }
            }
        }
    }

    for (int count = size - 2; count >= 0; count--) {
        if (count % 2 != 0) {
            for (int i = 0; i <= count; i++) {
                for (int j = 0; j <= count; j++) {
                    if (i + j == count) {
                        printf("%d ", matrix[size - i - 1][size - j - 1]);
                    }
                }
            }
        } else {
            for (int i = count; i >= 0; i--) {
                for (int j = count; j >= 0; j--) {
                    if (i + j == count) {
                        printf("%d ", matrix[size - i - 1][size - j - 1]);
                    }
                }
            }
        }
    }

    return 0;
}
