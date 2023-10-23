#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int sign(int a) {
    if (a < 0) {
        return -1;
    } else if (a == 0) {
        return 0;
    } else {
        return 1;
    }
}

void move(int count) {
    int i = -29;
    int j = 3;
    int l = 9;
    int result_k = -1;

    for (int k = 1; k <= count; k++) {
        i = (i * __max(i, j)) % 20 + (j * __min(i, l)) % 30 + k;
        j = (abs(i - j + l - k) * sign(k - 10)) % 20;
        l = (abs(i - j) * l - abs(j - l) * i + abs(i - l) * j) % 20 - k;
        if (((pow((i - 20), 2) / 100) + (pow(j, 2) / 25)) <= 1 && result_k == -1 && k <= 50) {
            result_k = k;
        }
    }
    if (result_k != -1) {
        printf("Getting into a given area in %d steps.\n", result_k);
    } else {
        printf("Hit in the specified area is not fixed.\n");
    }
    printf("The movement is stopped at a step %d.\n", count);
    printf("Stop at a point (%d, %d).\n", i, j);
    printf("The dynamic motion parameter is equal to %d.\n", l);
}

int main() {
    move(50);
    return 0;
}
