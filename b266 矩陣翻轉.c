#include <stdio.h>

//逆時針旋轉
void counterclockwise(int arr[10][10], int R, int C) {
    int arrA[10][10];
    for (int i=0; i<C; i++) {
        for (int j=0; j<R; j++) {
            arrA[i][j] = arr[i][j];
        }
    }
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            arr[i][j] = arrA[j][R-1-i];
        }
    }
}

//上下翻轉
void reverse(int arr[10][10], int R, int C) {
    int arrA[10][10];
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            arrA[i][j] = arr[i][j];
        }
    }
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            arr[i][j] = arrA[R-1-i][j];
        }
    }
}

int R, C, M;
int k[10];

int main() {
    scanf("%d %d %d", &R, &C, &M);

    int arr[10][10];
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i=0; i<M; i++) {
        scanf("%d", &k[i]);
    }
    for (int i=M-1; i>=0; i--) {
        int temp=0;
        switch(k[i]) {
            case 0:
                temp = C;
                C = R;
                R = temp;
                counterclockwise(arr, R, C);
                break;

            case 1:
                reverse(arr, R, C); 
                break;
        }
    }

    printf("%d %d\n", R, C);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C-1; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("%d\n", arr[i][C-1]);
    }
}