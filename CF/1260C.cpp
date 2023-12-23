#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	ll r, b, k; cin >> r >> b >> k;
	if (r > b) swap(r, b);
	if (gcd(r, b) + (k - 1) * r < b)
		cout << "REBEL\n";
	else cout << "OBEY\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}