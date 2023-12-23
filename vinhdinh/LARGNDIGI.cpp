#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c, n, l, r = 0;

ll bcnn(ll a, ll b){
	return a/gcd(a, b)*b;
}

ll solve(){
	for (int i = 0; i <= n - 1; i++) r = r*10 + 9;

	ll bc = bcnn(a, bcnn(b, c)), dem = r/bc;

	if (bc <= r) return bc*dem;
	else return -1;
}


int main(){
	cin >> a >> b >> c >> n;
	
	cout << solve();

	return 0;
}