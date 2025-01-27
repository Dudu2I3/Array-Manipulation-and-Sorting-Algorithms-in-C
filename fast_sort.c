#include <stdio.h>
#define N 10

int input(int *a);
int sort(int *a);
void output(int *a);
void quick_sort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void swap(int *a, int *b);
void shell_sort(int *arr);

int main() {
    int arr1[N], arr2[N];
    if (input(arr1) != 0) {
        printf("n/a");
        return 1;
    }
    for (int i = 0; i < N; i++) arr2[i] = arr1[i];
    quick_sort(arr1, 0, N - 1);
    shell_sort(arr2);
    output(arr1);
    output(arr2);
    return 0;
}

int input(int *a) {
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &a[i]) != 1) return -1;
    }
    if (getchar() != '\n') return -1;
    return 0;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shell_sort(int *arr) {
    int i, j, step;
    int tmp;
    for (step = N / 2; step > 0; step /= 2)
        for (i = step; i < N; i++) {
            tmp = arr[i];
            for (j = i; j >= step; j -= step) {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
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