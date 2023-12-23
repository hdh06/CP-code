#include <bits/stdc++.h>

using namespace std;

int const N = 1e9 + 1;

typedef long long ll;

int main(){
	ll a, b; cin >> a >> b;
	ll maxx = 0;
	for (ll i = 1, j = 9; j < N; i *= 10, j = j * 10 + 9){
		if (j < a || b < i) continue;
		ll cnt = 0;
		for (ll c = 1; c < N; c *= 10) if (a <= c && c < i) cnt++;
		cnt += min(b, j) - max(a, i) + 1;
		maxx = max(maxx, cnt); 
	}	
	cout << b - a + 1 - maxx;
	return 0;
}