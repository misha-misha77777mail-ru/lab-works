#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SIGN(a) ((a) < 0 ? -1 : (a) > 0 ? 1 : 0)
#define MOD(a, b) ((a) >= 0 ? (a) % (b) : ((a) + (b) - ((a) / (b) * (b))) % (b))
#define ABS(a) ((a) >= 0 ? (a) : -(a))
#define POW(a) ((a) * (a))


void move(int count) {
    int i = -29, j = 3, l = 9;
    int result_k = -1;

    for (int k = 0; k < count; k++) {
        int temp_i = i, temp_j = j, temp_l = l;

        i = MOD(temp_i * MAX(temp_j, temp_l), 20) + MOD(temp_j * MIN(temp_i, temp_l), 30) + k;
        j = MOD(ABS(temp_i - temp_j + temp_l - k) * SIGN(k - 10), 20);
        l = MOD(ABS(temp_i - temp_j) * temp_l - ABS(temp_j - temp_l) * temp_i + ABS(temp_i - temp_l) * temp_j, 20) - k;

        if ((((double)POW(i - 20) / 100.0) + ((double)POW(j) / 25.0)) <= 1 && result_k == -1 && k <= 50) {
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