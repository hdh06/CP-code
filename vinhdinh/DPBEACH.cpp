#include <bits/stdc++.h>

using namespace std;

int const N = 5001;

int main(){
	int n; 
	cin >> n;

	int arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	int L[N], R[N] = {};

	for (int i = n; i >= 1; i--){
		R[i] = 1;
		for (int j = i + 1; j <= n; j++) if (arr[i] < arr[j]){
			R[i] = max(R[i], R[j] + 1);
		}
	}

	int maxn = 0;
	for (int i = 1; i <= n; i++){
		L[i] = 1;
		int mR = 0;
		for (int j = i - 1;j > 0; j--){
			if (arr[j] < arr[i]) L[i] = max(L[i], L[j] + 1);
		}
		for (int j = 1; j <= n; j++) if (j != i){
			if (arr[j] > arr[i]){
				mR = max(mR, R[j]);
			}
		}
		maxn = max(maxn, L[i] + mR);
	}

	cout << maxn;
	return 0;
}