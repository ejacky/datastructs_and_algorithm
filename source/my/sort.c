
int Partition(int arr[], int low, int high) {
    int temp = arr[low];
    while (low < high) {
        while (temp < arr[high]) {
            high--;
        }
        arr[low] = arr[high];
        while (temp > arr[low]) {
            low++;
        }
        arr[high] = arr[low];
    }
    a[low] = temp;
    return low;
}

// 快排
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = Partition(arr, low, high);

        QuickSort(arr, low+1, pivot);
        QuickSort(arr, pivot, high-1)
    }
}

////// 堆排 //////
// 建堆
void BuildMaxHeap(ELemType A[], int len) {
    for (int i = len / 2; i > 0; i--) {
        HeadAdjust(A, i, len);
    }
}

// 大根堆即上一层均比下一层大
void HeadAdjust(ELemType A[], int k, int n) {
    A[0] = a[k];
    for (int i=2*k; i<n; i*=2) {
        if (i<len && A[i] < A[i+1]) { // 找出较大的子孩子
            i = i+1;
        }
        if A[0] >= A[i] { // 比较当前结点和较大子孩子
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