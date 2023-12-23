#include <bits/stdc++.h>

using namespace std;

long long const MOD = 1e9 + 7;

int main(){
	int n; cin >> n;
	long long tong = 0;
	while (n--){
		tong += ((((n + 1)%MOD)*((n + 1)%MOD))%MOD*(n + 1)%MOD)%MOD;
		tong %= MOD;
	}
	cout << tong;
	return 0;
}