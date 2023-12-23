#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e7 + 1;

bool sang[N] = {1, 1};
ll tong[N] = {};

int l, r;
ll ans = 0;

void init(){
	for (ll i = 2; i < N; i++){
		if (!sang[i]){
			for (ll j = i * i; j < N; j += i) sang[j] = true;
			for (ll j = i + i; j < N; j += i) tong[j] += i;
		}
		if (l <= i && i <= r)
			ans += tong[i];
	}
}

int main(){
	cin >> l >> r;
	init();
	cout << ans;
	return 0;
}