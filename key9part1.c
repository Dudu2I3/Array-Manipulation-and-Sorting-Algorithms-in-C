#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int n, arr[NMAX], ans[NMAX];

    if (input(arr, &n) != 0) {
        printf("n/a");
        return 1;
    }

    int sum = sum_numbers(arr, n);
    printf("%d\n", sum);

    int count = find_numbers(arr, n, sum, ans);
    output(ans, count);

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

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", buffer[i]);
    }
    printf("\n");
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }

    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count_num = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count_num++] = buffer[i];
        }
    }

    return count_num;
}