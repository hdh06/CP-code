#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
	
	if (a * x + b * y + c == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}