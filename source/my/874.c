#include <stdio.h>


typedef ELemType int 

void BuildMaxHeap(ELemType A[], int len) {
    for (int i = len / 2; i > 0; i--) {
        HeadAdjust(A, i, len);
    }
}

// 大根堆即上一层均比下一层大
void HeadAdjust(ELemType A[], int k, int n) {
    A[0] = a[k];
    for (int i=2*k; i<n; i*=2) {
        if (i<len && A[i] < A[i+1]) {
            i = i+1;
        }
        if A[0] >= A[i] {
            break;
        } else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void HeapSort(ELemType A[], int len) {
    for (int i=len; i>1; i--) {
        swap(A[i], A[1]);
        HeadAdjust(A, 1, n-1);
    }
}

// 折半查找
int BinSearch(int *arr, int key) {
    int min;
    int low = 0, high = len(arr);
    while (low <= high) {
        min = (high - low) / 2;
        if (key == arr[min]) {
            return min
        }
        if (key < arr[min]) {
            high = min - 1;
        }
        if (key > arr[min]) {
            low = min + 1;
        }
    }

    return -1;
}

// 快排
