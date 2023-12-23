#include <bits/stdc++.h>

using namespace std;

int const S = 1e6 + 6;
int const MOD = 1e9 + 7;

int f[S];

int main(){
	int n, s;
	cin >> n >> s;

	int coin[101];
	for(int i = 1; i <= n; i++){
		cin >> coin[i];
	}

	f[0] = 1;
	for (int i = 1; i <= s; i++){
		for (int j = 1; j <= n; j++){
			if (i - coin[j] >= 0){
				f[i] += f[i - coin[j]];
				f[i] %= MOD;
			}
		}
	}

	cout << f[s];
	return 0;
}