#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const R = 1023893, MOD = 123807237;
int const N = 10001;

int main(){
	int n; 
	cin >> n;
	string s; cin >> s;

	ll h[N] = {s[0]};
	ll p[N] = {1};

	for (int i = 1; i < n; i++) h[i] = (h[i - 1]*R + s[i]) % MOD, p[i] = p[i - 1]*R % MOD;

	for (int k = 1; k <= n; k++){
		set<ll> myset; bool flag = false;
		for (int i = 0; i < n - k + 1; i++){
			ll val = (h[i + k - 1] - (i - 1 >= 0?h[i - 1]:0)*p[k] + MOD*MOD) %MOD;
			if (myset.find(val) != myset.end()){
				flag = true; break;
			}
			myset.insert(val);
		}
		if (!flag){
			cout << k;
			return 0;
		}
	}
	return 0;
}