#include"total.h"
int merge(int arr[], int start, int mid, int end, int temp[]) {
    int i = start, j = mid + 1, k = 0, count = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else 
            count += (mid - i + 1),
            temp[k++] = arr[j++];
    }
    while (i <= mid)   
        temp[k++] = arr[i++];
    while (j <= end)  
        temp[k++] = arr[j++];
    for (int i = start, k = 0; i <= end; i++, k++)    
        arr[i] = temp[k];
    return count;
}
int mergeSort(int arr[], int start, int end, int temp[]) {
    if (start >= end)
        return 0;
    int mid = (start + end) / 2;
    int count = mergeSort(arr, start, mid, temp) + mergeSort(arr, mid + 1, end, temp) + merge(arr, start, mid, end, temp);
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    for (int i = start, k = 0; i <= end; i++, k++)
        arr[i] = temp[k];
    return count;
}
int Count(int arr[], int n) {
    int* temp = (int*)malloc(sizeof(int) * n);
    return mergeSort(arr, 0, n - 1, temp);
}
int minSortDistence(int arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swaps++;
    return swaps;
}
void problem_1() {
    srand((int)time(NULL));
    int* arr, n, x, t, sortDistanceResult, CountResult; char flag = 'y', c = 'y';
    while (c == 'y' || c == 'Y') {
        cout << "what is the biggest number you want to input?(the number is used to avoid repetition)   "; cin >> x;
        cout << "how many numbers do you want to input?(please less than " << x << "): "; cin >> n;  
        if (n > x)
            cout << "the number you input is larger than " << x 
                << " ,please input a number less than " << x << ":   ",
            cin >> n;
        else {
            arr = new int[n];
            cout << "do you want repetition in the array?(y/n)   "; cin >> flag;
            cout << "the initial array is:" << endl << "{";
            if (flag == 'n' ||flag == 'N') {
                for (int i = 0; i < n; i++) {
                    int re = 1;
                    do {
                        re = 0;
                        t = rand() % x + 1;
                        for (int j = 0; j < i; j++) {
                            if (arr[j] == t) {
                                re = 1;
                                break;
                            }
                        }
                    } while (re);
                    arr[i] = t;
                }
            }
            else 
                for (int i = 0; i < n; i++) 
                    arr[i] = rand() % x + 1;
            for (int i = 0; i < n; i++)
                if (i < n - 1)  cout << arr[i] << ",";
                else cout << arr[i] << "}";
            cout << endl << "the sorted arr is: " << endl << "{";
            sortDistanceResult = minSortDistence(arr, n);
            CountResult = Count(arr, n);
            for (int i = 0; i < n; i++) {
                if (i < n - 1)  cout << arr[i] << ",";
                else cout << arr[i] << "}";
            }
            cout << endl;
            cout << "Reverse count: " << CountResult << endl
                << "Sort distance: " << sortDistanceResult << endl
                << "whether to start problem_1 again?(y/n)     ";
            cin >> c;    delete[] arr;
        }
    }
}
