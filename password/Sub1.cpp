#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

int n, a, b; 

bool c1(int x){
	int tong = 0;
	while (x > 0){
		tong += x % 10;
		x /= 10;
	}
	return tong % a == 0;
}

bool c2(int x){
	return x % b == 0;
}


int main(){
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = 0; i < pow(10, n); i++){
		(ans += (c2(i) && c1(i))) %= MOD;
	}
	
	cout << ans;
	return 0;
}