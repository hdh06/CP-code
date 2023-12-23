#include <bits/stdc++.h>

using namespace std;

typedef long double ldb;

int main(){
	int n, k; cin >> n >> k;
	ldb ans = 0, prev = 0;
	for (int i = 1; i <= k; i++){
		ldb x = (ldb) i / (ldb) k;
		ldb curr = 1;
		for (int i = 1; i <= n; i++)
			curr *= x;
		ans += 1.0L * (curr - prev) * i;
		prev = curr;
	}
	cout << fixed << setprecision(6) << ans;
	return 0;
}