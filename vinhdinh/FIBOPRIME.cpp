#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 74;

ll f[N] = {0, 1, 1};

void init(){
	int i = 3;

	for (;i < N; i++){
	 	f[i] = f[i - 1] + f[i - 2];
	 	if (f[i] > (ll)1e15) break;
	}
}

bool primeCheck(ll n){
	if (n < 2) return false;
	for (ll i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;
	return true;
}

int main(){
	init();
	ll a, b;
	cin >> a >> b;

	int dem_a = 0, dem_b = 0;
	for (int i = 1; i < N && f[i] < a; i++) if (primeCheck(f[i])) dem_a++;
	for (int i = 1; i < N && f[i] <= b; i++) if (primeCheck(f[i])) dem_b++;
	cout << dem_b - dem_a;
	
	return 0;
}