#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

typedef long long ll;

int mpow(int x, ll n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int main(){
	int n; cin >> n;
	int arr[N][2];
	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];	

	ll nod = 1;
	for (int i = 1; i <= n; i++) (nod *= (arr[i][1] + 1) % MOD) %= MOD;

	ll sod = 1;
	for (int i = 1; i <= n; i++) (sod *= 1LL * (mpow(arr[i][0], arr[i][1] + 1) - 1 + MOD) % MOD * mpow(arr[i][0] - 1, MOD - 2) % MOD) %= MOD;

	ll cnod = 1;
	ll pod = 1;
	for (int i = 1; i <= n; i++){
		pod = 1LL * mpow(pod, arr[i][1] + 1) * mpow(mpow(arr[i][0], 1LL * arr[i][1] * (arr[i][1] + 1) / 2), cnod) % MOD;
		(cnod *= (arr[i][1] + 1) % (MOD - 1)) %= MOD - 1;
	}
	cout << nod << " " << sod << " " << pod;
	return 0;
}