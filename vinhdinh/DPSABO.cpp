#include <bits/stdc++.h>

int const MOD = 1e6;

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	int f[10001] = {1,2};
	for (int i = 2; i <= n; i++){
		if (i - k - 1 >= 0) f[i] = (f[i - k - 1] + f[i - 1])%MOD;
		else f[i] = (f[i - 1] + 1)%MOD;   
	}

	cout << f[n];

	return 0;
}