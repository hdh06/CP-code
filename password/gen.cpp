#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

int const N = 200;
int const A = 200;
int const B = 200;

int main(){
	freopen("retest12.out", "w", stdout);
	cout << rand(9, N) << " ";
	cout << rand(1, A) << " ";
	cout << rand(2, B);
	return 0;
}