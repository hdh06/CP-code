#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

long long mpow(long long n, long long x){
	if (x == 0) return 1;

	long long ans = mpow(n, x / 2);
	ans = (ans*ans)%MOD;
	if (x % 2 != 0) ans = (ans*n)%MOD;

	return ans;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		cout << mpow(a, b) << endl;
	}
	return 0;
}