#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	ll a, b, c, d; cin >> a >> b >> c >> d;
 	if (b > d)
		a *= pow(10LL, min(9LL, b - d));
	else c *= pow(10LL, min(9LL, d - b));
	if (a < c) cout << "<\n";
	else if (a == c) cout << "=\n";
	else cout << ">\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}