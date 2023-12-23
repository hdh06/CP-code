#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

void solve(ll a, ll b, ll c, ll d){
	ll uclnbd = gcd(b, d);
	ll bcnn = b/uclnbd * d;
	ll tong = a*(bcnn/b) + c*(bcnn/d);
	ll ucln = gcd(tong, bcnn);
	cout << tong/ucln << "/" << bcnn/ucln << endl;
	// cout << bcnn << " " << tong << " " << ucln;
}

int main(){
	ll a, b, c, d;
	while(cin >> a >> b >> c >> d){
		solve(a, b, c, d);
	}
	return 0;
}