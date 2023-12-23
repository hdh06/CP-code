#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int const N = 1e5 + 1;

int n, arr[N];
ll S;

ll calc(ll m){
	ll tong = 0;
	for (int i = 1; i <= n; i++){
		if (arr[i] > m) tong += m;
		else tong += arr[i];
	}
	return tong;
}

ll tknp(ll l, ll r){
	if (r < l) return LLONG_MAX;
	ll mid = (l + r)>>1;
	ll kq = calc(mid);
	if (kq == S) return mid;
	
	if (kq < S) return tknp(mid + 1, r);
	if (kq > S) return min(mid, tknp(l, mid - 1));
}

int main(){
	cin >> n >> S;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	ll ans = tknp(1, (ll)1e11);
	cout << (ans == LLONG_MAX?-1:ans);
	return 0;
}