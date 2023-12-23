#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}


bool pc(int x){
	if (x < 2) return false;
	for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return false;
	return true;	
}

int get(int l, int r){
	int x = rand(l, r);
	while (!pc(x)) x = rand(l, r);
	return x;
}

int main(){
	freopen("test182.inp", "w", stdout);
	cout << 100 << "\n";
	for (int i = 1; i <= 100; i++){	
		cout << (int)pow(get(700, 1000), rand(2, 3)) << "\n";
	}
	return 0;
}