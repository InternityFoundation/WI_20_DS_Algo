#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
bool findit(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * arr[i];
    }
    sort(arr, arr + n);

    for (int i = n - 1; i >= 2; i--) {
        int l = 0;
        int r = n - 2;
        while (l < r) {
            if (arr[l] + arr[r] == arr[i]) {
                return true;
            }
            if (arr[l] + arr[r] < arr[i]) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    return false;
}
int main()
{
		int arr[] = { 1,2,3,4,5,6 };
		int n = sizeof(arr) / sizeof(int);
        if (findit(arr, n) == true) {
            cout << "The triplets are present in the array" << endl;
        }
        else {
            cout << "The triplets are NOT present in the array" << endl;
        }
}
