#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, d1, d2;
	cin >> n >> k >> d1 >> d2;
	int mgcd = gcd(d1, d2);

	int ans = 0;

	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		if (abs(t - k) % mgcd == 0) ans ++;
	}	

	cout << ans;
	return 0;
}