#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	ll sum = 0, maxx = 0;
	for (int i = 1; i <= n; i++){
		ll x; cin >> x;
		sum += x, maxx = max(maxx, x);
	}

	cout << max(sum, 2 * maxx);
	return 0;
}