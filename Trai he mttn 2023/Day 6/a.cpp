#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n; cin >> n;
	ll ans = 0;
	for (int i = 60	; i >= 0; i--){
		if (n >= (1LL << i) * 3){
			n -= (1LL << i) * 3;
			ans += 1LL << i;
		}
	}
	cout << ans;
	return 0;
}