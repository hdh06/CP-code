#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

string const file = "gen";

int main(){
	freopen("test07.inp", "w", stdout);
	int n = rand(5e5, 5e5), q = rand(5e5, 5e5);
	// int k = 2;
	// int l = 1, r = n;
	cout << n << " " << q << "\n";
	for (int i = 1; i <= 100; i++){
		int l = rand(1, 1);
		int r = rand(n, n);
		int k = rand(1, cbrt(n));
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}
	for (int i = 101; i <= 200; i++){
		int l = rand(1, n);
		int r = rand(l, n);
		int k = rand(1, 1);
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}
	for (int i = 111; i <= 120; i++){
		int l = rand(1, n - 1);
		int r = rand(l, n - 1);
		int k = rand(r + 1, n);
		// int k = rand(1, n);
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}
	for (int i = 121; i <= 180; i++){
		int l = rand(1, sqrt(n));
		int r = rand(l, n);
		int k = rand(1, 10);
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}
	for (int i = 181; i <= 190; i++){
		int l = rand(5, n - 5);
		int r = rand(l, n - 5);
		int k = rand(1, 13);
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}
	for (int i = 191; i <= 200; i++){
		int l = rand(1, n - 1);
		int r = rand(l, n - 1);
		int k = rand(1, 2000);
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}
	for (int i = 201; i <= 210; i++){
		int k = rand(sqrt(n), n);
		int l = rand(k, n);
		int r = rand(l, n);
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}
	for (int i = 211; i <= 250; i++){
		int l = rand(5, 5);
		int r = rand(n - 5, n - 5);
		int k = rand(1, 5);
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}

	for (int i = 251; i <= 70000; i++){
		int l = rand(1, n);
		int r = rand(l, n);
		int k = rand(1, 1);
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}

	for (int i = 70001; i <= 140000; i++){
		int l = rand(1, 100);
		int r = rand(1e5, n);
		int k = rand(1, cbrt(n));
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}

	for (int i = 140000; i <= q; i++){
		int l = rand(1, 10);
		int r = rand(2e5, n);
		int k = rand(1, cbrt(n));
		int x = rand(5e7, 1e9);
		cout << l << " " << r << " " << k << " " << x << "\n";
	}
	return 0;
}