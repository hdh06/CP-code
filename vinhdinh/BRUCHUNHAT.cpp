#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ldb;

ldb calc(ll a, ll b){
	ll minn = LLONG_MAX;
	for (ll x = 0; x <= min(a, b); x++){
		minn = min(minn, x*x -a*x + a*b);
	}
	return minn;
}

int main(){
	ldb a, b;	
	cin >> a >> b;
	cout << setprecision(1) << fixed;
	cout << a*b/2 << "\n" << calc(a, b)/(ldb)2;
	return 0;
}