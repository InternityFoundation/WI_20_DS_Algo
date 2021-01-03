#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int arr[],int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n && j!=i && j != i - 1 && j != i + 1; j++) {
            sum = max(sum, arr[i] + arr[j]);
        }
    }
    return sum;
}
int main()
{
    int arr[] = { 5, 1, 1, 5, 6 };
    int n = sizeof(arr) / sizeof(int);
    int v = solve(arr, n);
    cout << v;
    cout << endl;
}