#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SIGN(a) ((a) < 0 ? -1 : (a) > 0 ? 1 : 0)
#define MOD(a, b) ((a) >= 0 ? (a) % (b) : ((b) + (a) - ((a) / (b) * (b))) % (b))

void move(int count) {
    int i = -29;
    int j = 3;
    int l = 9;
    int result_k = -1;
    for (int k = 0; k <= count; k++) {
        int temp_i = i;
        int temp_j = j;
        int temp_l = l;
        i = MOD((temp_i * MAX(temp_i, temp_j)), 20) + MOD((temp_j * MIN(temp_i, temp_l)), 30) + k;
        j = MOD(abs(temp_i - temp_j + temp_l - k) * SIGN(k - 10), 20);
        l = MOD(abs(temp_i - temp_j) * temp_l - abs(temp_j - temp_l) * temp_i + abs(temp_i - temp_l) * temp_j, 20) - k;
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
