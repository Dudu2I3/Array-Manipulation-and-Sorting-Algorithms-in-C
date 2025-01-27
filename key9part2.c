#include <stdio.h>

#define LEN 100

int input(int *buff);
void output(int *buff, int len);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

int main() {
    int len1, len2, res_len;
    int arr1[LEN], arr2[LEN], res[LEN];
    len1 = input(arr1);
    len2 = input(arr2);
    if (len1 == 0 || len2 == 0) {
        printf("n/a");
        return 0;
    }
    printf("%d\n", len1);
    printf("%d\n", len2);
    output(arr1, len1);
    output(arr2, len2);
    sub(arr1, len1, arr2, len2, res, &res_len);
    output(res, res_len);
    return 0;
}

int input(int *buff) {
    int num;
    char space;
    int i = 0;
    while ((scanf("%d%c", &num, &space)) == 2 && 0 <= num && num < 10) {
        buff[i++] = num;
        if (space == '\n') return i;
    }
    return 0;
}

void output(int *buff, int len) {
    for (int i = 0; i < len; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", buff[i]);
    }
    printf("\n");
}

/*void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    for (int i = len1; i > 0; i--){
        for (int j = len2;j > 0;j--){
            if ((arr1[i] + arr[2]) < 10) result[-1] = (arr1[i] + arr[2]);
        }
    }
}*/

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int i = len1 - 1;
    int j = len2 - 1;
    *result_length = i;
    while (i > 0 && j > 0) {
        if (buff1[i] >= buff2[j]) {
            result[i] = buff1[i] - buff2[j];
            i--;
            j--;
        } else {
            result[i] = 10 - buff2[j] + buff1[i];
            i--;
            j--;
        }
        while (j == 0 && i > 0) {
            result[i] = buff1[i];
            i--;
        }
    }
}
