#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 100;

ll f[N] = {0, 1, 1};

void init(){
	for (int i = 3; i < N; i++) f[i] = f[i - 1] + f[i - 2];
	// for (int i = 0; i < N; i++) cout << f[i] << " "; cout << endl;
}

int main(){
	init();
	int t; cin >>t;
	while(t --){
		ll n;
		cin >> n;

		if (n == 0){
			cout << "YES";
			continue;
		}

		bool flag = false;
		for (ll i = 1; i < N - 1; i++){
			for (ll j = i; j < N; j++){
				if (n % f[j] == 0 && f[i] == n/f[j]){
					flag = true;
					break;
				}
			}
			if (flag) break;
		}

		if (flag) cout << "YES";
		else cout << "NO";
		cout << endl;
	}	
	return 0;
}