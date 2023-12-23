#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

string const file = "fourking";

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
	freopen((file + ".inp").c_str(), "w", stdout);
	int t = rand(100, 100); cout << t << "\n";
	// vector<int> p = {17, 19};
	for (int i = 1; i <= t; i++){
		cout << 1LL * 2 * 3 * 5 * 7 * 11 * 13 * 15 * 17 * 19 * 23 * 29 * 2 * 2 * 2 << "\n";
	}
 	return 0;
}