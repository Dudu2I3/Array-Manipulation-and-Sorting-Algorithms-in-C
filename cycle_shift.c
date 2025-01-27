#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void shift_one_left(int *a, int n);
void shift_left(int *a, int n, int shift_size);
void shift_right(int *a, int n, int shift_size);

int main() {
    int n, shift, arr[NMAX];

    if (input(arr, &n) != 0) {
        printf("n/a");
        return 1;
    }
    if (scanf("%d", &shift) == 1) {
        if (shift >= 0)
            shift_left(arr, n, shift);
        else
            shift_right(arr, n, shift);
    } else {
        printf("n/a");
        return 1;
    }
    output(arr, n);
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
    if (getchar() != '\n') return -1;
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

void shift_one_left(int *a, int n) {
    int tmp = a[0];
    for (int i = 1; i < n; i++) {
        a[i - 1] = a[i];
    }
    a[n - 1] = tmp;
}

void shift_left(int *a, int n, int shift_size) {
    shift_size = shift_size % n;
    for (int i = 0; i < shift_size; i++) {
        shift_one_left(a, n);
    }
}

void shift_right(int *a, int n, int shift_size) {
    shift_size = shift_size % n;
    shift_size = n + shift_size;

    for (int i = 0; i < shift_size; ++i) {
        shift_one_left(a, n);
    }
}
