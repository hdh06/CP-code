#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int main(){
	int n, d; cin >> n;	cin >> d;

	int arr[N] = {};

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	sort(arr + 1, arr + n + 1);

	int minn = n;

	for (int i = 1; i <= n; i++){
		int j = i;
		while (j <= n && arr[j] - arr[i] <= d) j++;
		j--;

		minn = min(minn, n - (j - i + 1));
		// cout << "[" << i << "," << j << "] ";
	}

	cout << minn;
	return 0;

}