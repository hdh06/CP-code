#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const N = 1e6 + 6;
ll const MOD = 1e9 + 7;

ll tong[N] = {}, tong2[N] = {}, dem[N] = {}; 

void init(){
	bool sang[N] = {1, 1};
	for (ll i = 2; i < N; i++){
		tong[i] = tong[i - 1];
		tong2[i] = tong2[i - 1];
		dem[i] = dem[i - 1];
		if (!sang[i]){
			for (ll j = i*i; j < N; j += i) sang[j] = true;
			tong[i] += ((i%MOD)*((++dem[i])%MOD))%MOD; tong[i] %= MOD;
			tong2[i] += i; tong2[i] %= MOD;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	init();
	int t; cin >> t;
	while(t > 0){
		t--;
		int l, r; cin >> l >> r;
		if (l == 0) l = 1;
		cout << (tong[r] - tong[l - 1] + MOD - ((dem[l - 1]%MOD)*((tong2[r] - tong2[l - 1])%MOD))%MOD + MOD)%MOD << "\n";
	}
	return 0;
}