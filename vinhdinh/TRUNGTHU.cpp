#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	sort(arr.begin() + 1, arr.end());
	// for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
	int maxn = 0;
	for (int i = 1, j = n;i < j;){
		// cout << "BEDBUG: " << i << " " << j << endl; 
		if (arr[i] + arr[j] == k){
			cout << k;
			return 0;
		}
		if (arr[i] + arr[j] < k) maxn = max(maxn, arr[i] + arr[j]), i++; 
		else if (arr[j] + arr[j] > k) j--;
	}

	cout << maxn;
	return 0;
}

/*
6 18
5 3 10 2 4 9
*/