#include <bits/stdc++.h>
using namespace std;

void sortSquares(int arr[], int n)
{

	int K = 0;
	for (K = 0; K < n; K++)
		if (arr[K] >= 0)
			break;

	int i = K - 1;
	int j = K;
	int ind = 0;


	int temp[n];
	while (i >= 0 && j < n) {
		if (arr[i] * arr[i] < arr[j] * arr[j]) {
			temp[ind] = arr[i] * arr[i];
			i--;
		}
		else {
			temp[ind] = arr[j] * arr[j];
			j++;
		}
		ind++;
	}


	while (i >= 0) {
		temp[ind] = arr[i] * arr[i];
		i--;
		ind++;
	}


	while (j < n) {
		temp[ind] = arr[j] * arr[j];
		j++;
		ind++;
	}


	for (int i = 0; i < n; i++)
		arr[i] = temp[i];
}


int main()
{
	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }


	sortSquares(a, n);


	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}

