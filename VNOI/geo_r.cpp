#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll x0, y0, x1, y1, a, b, c; cin >> x0 >> y0 >> x1 >> y1 >> a >> b >> c;	
	if ((a * x0 + b * y0 + c) * (a * x1 + b * y1 + c) > 0)
		cout << "YES\n";
	else cout << "NO\n";
	return 0;
}