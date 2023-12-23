#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

ll n; 

ll f(ll x){
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		ans += min(n, x / i);
	return ans;
}

int main(){
	cin >> n;
	
	ll ans = -1;
	for (ll l = 1, r = n * n; l <= r;){
		ll mid = (l + r) >> 1;
		if ((n * n + 1) / 2 <= f(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	} 
	
	cout << ans;
	return 0;
}