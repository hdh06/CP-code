#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int calc(int n, int k, bool st){
	// debug(n, k, st);
	int r = (n + st) / 2;
	if (r < k){
		int x = calc(n - r, k - r, st ^ (n & 1));	
		return 2 * x - !st;
	}
	return 2 * k - st;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		cout << calc(n, k, 0) << "\n";
	}
	return 0;
}