#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
bool findit(int arr[], int n, int target) {

    bool flag = false;
    int *duparr=new int[n];

    for (int i = 0; i < n; i++) {
        duparr[i] = arr[i];
    }
    sort(duparr, duparr + n);
    int l = 0;
    int r = n - 1;
    while (l < r) {
        if (duparr[l] + duparr[r] == target) {
            flag = true;
            for (int i = 0; i < n; i++) {
                if (arr[i] == duparr[l] || arr[i] == duparr[r]) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
        if (duparr[l] + duparr[r] < target) {
            l++;
        }
        else {
            r--;
        }
    }
    return flag;
}

int main()
{
		int arr[] = { 1,2,3,4,5,6 };
        int target = 11;
		int n = sizeof(arr) / sizeof(int);
        if (findit(arr, n, target) == true) {
        }
        else {
            cout << "No such pair is present"<<endl;
        }
}
