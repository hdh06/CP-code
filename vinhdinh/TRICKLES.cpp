#include <bits/stdc++.h>

using namespace std;

int const V = 5001;
int const N = 2e5 + 1;
int const MOD = 1e9 + 7;

int main(){
	int n; cin >> n;
	int fre[V] = {};
	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		fre[t]++;
	}

	int fre2[V] = {};

	int tich = 1;

	for (int k = 0; k < V; k++){
		for (int i = k + 1; i < V; i++) 
			if ((3*i + 5*k) % 3 == 0 || (3*i + 5*k) % 5 == 0 || (3*i + 5*k) % 8 == 0){
				int d = (fre2[i]*fre[k]) % MOD;
				if (d != 0) tich = tich*(i - k) % MOD * d % MOD;
			}	
		for (int j = k - 1; j >= 0; j--){
			(fre2[j + k] += fre[j]*fre[k]) %= MOD;
		}
	}

	cout << tich;
	return 0;
}