#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n), f(n + 1, INT_MAX), L(n, 0), R(n, 0);

	for(auto &x: arr) cin >> x;

	f[0] = INT_MIN;

	for (int i = 0; i < n; i++){
		int k = lower_bound(f.begin(), f.end(), arr[i]) - f.begin();

		f[k] = arr[i];
		L[i] = k;
	}	

	f.assign(n + 1, INT_MAX);
	f[0] = INT_MIN;

	reverse(arr.begin(), arr.end());

	for (int i = 0; i < n; i++){
		int k = lower_bound(f.begin(), f.end(), arr[i]) - f.begin();

		f[k] = arr[i];
		R[i] = k;
	}	

	reverse(R.begin(), R.end());

	int maxn = 0;
	for (int i = 0; i < n; i++) {
		if (L[i] > 1 && R[i] > 1){ 
			maxn = max(maxn, L[i] + R[i] - 1);
		}
	}	
	cout << maxn;
	return 0;
}