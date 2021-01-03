#include <iostream>
#include<vector>
using namespace std;

void solve(int arr[], int n) {
    int l = 0, r = n - 1;
    int* result = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        if (abs(arr[l]) > abs(arr[r])) {
            result[i] = arr[l] * arr[l];
            l++;
        }
        else {
            result[i] = arr[r] * arr[r];
            r--;
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main()
{
    int arr[] = { -9, -2, 0, 2, 3 };
    int n = sizeof(arr) / sizeof(int);
    solve(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
    }
    cout << endl;
}