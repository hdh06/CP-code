#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

ll calc(ll x){
	int k = log10(x) + 1;
	ll p = 1;
	while (k--) p *= 10;
	return x * (p - x - 1);
}

int main(){
	ll A, B; cin >> A >> B;
	
	ll ans = max(calc(A), calc(B));
	ll p = 5;
	for (int i = 1; i <= 9; i++){
		if (A <= p && p <= B) ans = max(ans, calc(p));
		p *= 10;
	}
	cout << ans;
	return 0;
}