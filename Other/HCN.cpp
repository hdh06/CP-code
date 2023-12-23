#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n; 

	vector<int> arr(n + 2, 0), L(n + 2, 0), R(n + 2, 0);

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		// L[i] = R[i] = arr[i];
	}

	arr[0] = arr[n + 1] = 1e9;

	for (int i = 1; i <= n; i++) if (arr[i - 1] > arr[i]) L[i] = L[i - 1] + 1;
	for (int i = n; i >= 1; i--) if (arr[i + 1] > arr[i]) R[i] = R[i + 1] + 1;

	int maxn = 0;

	for (int i = 1; i <= n; i++){
		maxn = max(maxn, (L[i] + R[i] + 1)*arr[i]);
	}

	cout << maxn;
	return 0;
}