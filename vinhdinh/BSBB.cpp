#include <bits/stdc++.h>

using namespace std;

// int const N = 1e6 + 1;
typedef long long ll;

int tknp(int l, int r, ll p, int s){
	if (l >= r) return l;
	ll mid = (l + r)/2;

	if (p*mid == s) return mid;
	if (p*mid < s) return tknp(mid + 1, r, p, s);
	if (p*mid > s) return tknp(l, mid - 1, p, s);

}

int main(){
	int n;
	cin >> n;

	int dem = 0;
	for (ll i = 1; i <= n - 1; i++){
		ll ans = tknp(1, n, i, n);
		dem += ans - (ans*i >= n);
		// cout << ans << endl;
	}

	cout << dem;
	return 0;
}	