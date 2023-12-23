#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;

ll g(ll x){
	ll tong = 0;
	while (x > 0){
		tong += x&1;
		x >>= 1;
	}
	return tong;
}

int main(){
	int n; ll V;
	cin >> n >> V;	

	ll sum[N] = {};

	for (int i = 1; i <= n; i++){
		int temp; cin >> temp;
		sum[i] = sum[i - 1] + g(temp);
	}

	int mink = INT_MAX;

	for (int i = 1; i <= n; i++){
		int k = lower_bound(sum + i, sum + n + 1, V + sum[i - 1]) - (sum + i) + 1;
		if (i + k - 1 <= n) mink = min(mink, k);
	}

	cout << (mink == INT_MAX?-1:mink);
	return 0;
}