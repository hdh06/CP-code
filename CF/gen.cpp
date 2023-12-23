#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

int main(){
	freopen("test.inp", "w", stdout);
	int t = rand(1, 1);
	cout << t << "\n";
	while (t--){
		int n = rand(3, 3), m = rand(4, 4);
		cout << n << " " << m << "\n";
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cout << (rand(0, 1)? 1: -1) << " \n"[j == m];
	}
	return 0;
}