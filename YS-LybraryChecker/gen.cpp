#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

#define file "inp"

int const N = 2e5;
int const THAT = 998244353 - 1;

int main(){
	freopen(file".inp", "w", stdout);
	int n = rand(N, N), q = rand(N, N);
	cout << n << " " << q << "\n";
	for (int i = 1; i <= n; i++)
		cout << rand(1, THAT) << " " << rand(0, THAT) << "\n";
	for (int i = 1; i < n; i++)
		cout << rand(0, i - 1) << " " << i << "\n";
	for (int i = 1; i <= q; i++){
		int t = rand(0, 1); cout << t << " ";
		if (!t){
			cout << rand(0, n - 1) << " " << rand(1, THAT) << " " << rand(0, THAT) << "\n";
		}else{
			cout << rand(0, n - 1) << " " << rand(0, n - 1) << " " << rand(0, THAT) << "\n";
		}
	}
	return 0;
}