#include <vector>

vector<int> bubble_sort(vector<int> arr) {
    int n = arr.size();

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}


// void bubble_sort(int arr[], int n) {
//     // bubble sort
//     for (int i = n - 1; i >= 0; i--) {
//         int didSwap = 0;
//         for (int j = 0; j <= i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 int temp = arr[j + 1];
//                 arr[j + 1] = arr[j];
//                 arr[j] = temp;
//                 didSwap = 1;
//             }
//         }
//         if (didSwap == 0) {
//             break;
//         }
//     }