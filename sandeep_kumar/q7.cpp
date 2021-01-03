#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findit(int arr[], int n)
{
    int s = 0,e=0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            s = i;
            break;
        }
    }
    if (s == n - 1) {
        return { 0,0 };
    }
    for (int i = n-1; i >=0; i--) {
        if (arr[i] < arr[i - 1]) {
            e = i;
            break;
        }
    }

    int maximum = arr[s], minimum = arr[s];
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    for (int i = 0; i < s ; i++) {
        if (arr[i]>minimum) {
            s = i;
            break;
        }
    }
    for (int i = n-1; i >= s+1; i--) {
        if (arr[i]<maximum) {
            e = i;
            break;
        }
    }
    return { s,e };
}
int main()
{
    int arr[] = { 3, 7, 5, 6, 9 };
    int n = sizeof(arr) / sizeof(int);
    vector <int> v = findit(arr, n);
    cout << v[0] << " " << v[1];
}
