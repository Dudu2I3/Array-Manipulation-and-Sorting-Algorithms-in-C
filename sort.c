#include <stdio.h>
#define N 10

int input(int *a);
int sort(int *a);
void output(int *a);

int main() {
    int arr[N];
    if (input(arr) != 0) {
        printf("n/a");
        return 1;
    }
    sort(arr);
    output(arr);
    return 0;
}

int input(int *a) {
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &a[i]) != 1) return -1;
    }
    if (getchar() != '\n') return -1;
    return 0;
}

int sort(int *a) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    return 0;
}

void output(int *a) {
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}