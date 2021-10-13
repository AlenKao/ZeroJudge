#include <stdio.h>
#include <stdlib.h> 
#define SWAP(x, y) {int t; t=x; x=y; y=t;}

int partition(int[], int, int);
void quickSort(int[], int, int);
int binarySearch(int[], int, int, int);

int stuNum=0;
int main () {
    scanf("%d", &stuNum);

    int score[20];
    for (int i=0; i<stuNum; i++) {
        scanf("%d", &score[i]);
    }

    //quick sort
    quickSort(score, 0, stuNum-1);
    int index = binarySearch(score, 0, stuNum-1, 60);

    //output
    for (int i=0; i<stuNum-1; i++) {
        printf("%d ", score[i]);
    }
    printf("%d\n", score[stuNum-1]);

    //worst case
    if (score[stuNum-1] < 60) {
        printf("%d\n", score[stuNum-1]);
        printf("worst case\n");
    }

    //best case
    else if (score[0] > 60) {
        printf("best case\n");
        printf("%d\n", score[0]);
    }

    else {
        printf("%d\n", score[index-1]);
        printf("%d\n", score[index]);
    }
}

int binarySearch(int number[], int low, int upper, int find) {
    int mid;
    while (low<=upper) {
        mid = (low+upper)/2;
        if (number[mid]<find) {
            low = mid+1;
        }else if (number[mid]>find) {
            upper = mid-1;
        }else {
            return mid;
        } 
    }
    return low;
}

int partition(int number[], int left, int right) {
    int i = left-1;
    int j;
    for (int j=left; j<right; j++) {
        if (number[j] <= number[right]) {
            i++;
            SWAP(number[i], number[j]);
        }
    }

    SWAP(number[i+1], number[right]);
    return i+1;
}

void quickSort(int number[], int left, int right) {
    if (left<right) {
        int q = partition(number, left, right);
        quickSort(number, left, q-1);
        quickSort(number, q+1, right);
    }
}