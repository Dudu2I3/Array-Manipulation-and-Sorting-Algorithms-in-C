#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int searh_num(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        printf("n/a");
        return 1;
    }
    printf("%d", searh_num(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > NMAX) {
        return -1;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return -1;
        }
    }
    return 0;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    double sum = 0;
    double mean1 = mean(a, n);
    for (int i = 0; i < n; i++) {
        sum += (a[i] - mean1) * (a[i] - mean1);
    }
    return sum / n;
}

int searh_num(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 == 0) && (a[i] >= mean(a, n)) && (a[i] <= (mean(a, n) + 3 * sqrt(variance(a, n)))) &&
            (a[i] != 0))
            return a[i];
    }
    return 0;
}
