#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll a, b, c, r; cin >> a >> b >> c >> r;	
	cout << setprecision(6) << fixed << a << " " << b << " " << c - sqrtl(a * a + b * b) * r << "\n";
	cout << setprecision(6) << fixed << a << " " << b << " " << c + sqrtl(a * a + b * b) * r << "\n";
	return 0;
}