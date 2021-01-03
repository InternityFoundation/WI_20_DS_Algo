#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> solve(int arr[],int n)
{
    vector <int> v;
    v.push_back(1);
    if (n == 1)
        return v;
    int k = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            k++;
        }
        else {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    k--;
                }
            }
        }
        v.push_back(k);
    }
    return v;
}
int main()
{
    int arr[] = { 10, 40, 200, 1000, 60, 30 };
    int n = sizeof(arr) / sizeof(int);
    vector <int> v = solve(arr, n);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}