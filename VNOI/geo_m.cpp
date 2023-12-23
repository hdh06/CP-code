#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll x, y, u, v; cin >> x >> y >> u >> v;
	
	ll a = u;
	ll b = v;
	ll c = a * x + b * y;
	
	cout << a << " " << b << " " << - c;
	//ax + by = c;
	return 0;	
}