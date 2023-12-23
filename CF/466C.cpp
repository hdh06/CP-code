#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	vector<int> arr(n + 1); ll S = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		S += arr[i];
	}

	if (S % 3 != 0){
		cout << 0; return 0;
	}

	vector<int> cnt(n + 2);


	for (ll i = n, tong = 0; i >= 1; i--){
		tong += arr[i];
		cnt[i] = cnt[i + 1] + (tong == S/3);
	}	

	ll dem = 0;

	for (ll i = 1, tong = 0; i <= n - 2; i++){
		tong += arr[i];
		dem += 1LL*cnt[i + 2]*(tong == S/3);
	}

	cout << dem;
	return 0;
}