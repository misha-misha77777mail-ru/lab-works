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



    for (int count = size - 3; count >= 0; count -= 2) {
        int cache = 0;
        for (int i = count; i < size; i++) {
            for (int j = 0; j <= size - count - 1; j++) {
                if (i - j == count) {
                    cache += matrix[i][j];
                }
            }
        }
        matrix[(size - count - 1) / 2 + count][(size - count - 1) / 2] = cache;
    }
    for (int count = size - 3; count > 1; count -= 2) {
        int cache = 0;
        for (int i = 0; i < size - count; i++) {
            for (int j = count; j < size; j++) {
                if (j - i == count) {
                    cache += matrix[i][j];
                }
            }
        }
        matrix[(size - count - 1) / 2][(size - count - 1) / 2 + count] = cache;
    }

    printf("\n\nNew matrix:\n");
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
