
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

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = Partition(arr, low, high);

        QuickSort(arr, low+1, pivot);
        QuickSort(arr, pivot, high-1)
    }
}