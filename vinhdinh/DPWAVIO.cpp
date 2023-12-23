#include <bits/stdc++.h>

using namespace std;

int const N = 5051;

int main(){
	int n;
	cin >> n; 

	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int L[N] = {}, R[N] = {};

	for (int i = 1; i <= n; i++){
		L[i] = 1;
		for (int j = i - 1; j >= 1; j--) if(arr[j] < arr[i]) L[i] = max(L[i], L[j] + 1);
	}

	for (int i = n; i >= 1; i--){
		R[i] = 1;
		for (int j = i + 1; j <= n; j++) if(arr[j] < arr[i]) R[i] = max(R[i], R[j] + 1);
	}


	int maxn = 1;
	for (int i = 1; i <= n; i++){
		// cout << L[i] << " " << R[i] << endl;
		if (L[i] != 1 && R[i] != 1)
		maxn = max(maxn, L[i] + R[i] - 1);
	}

	cout << maxn;
	return 0;
}