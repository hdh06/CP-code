#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double angle(ll x, ll y){
	if (y > 0)
		return acos(x / sqrtl(x * x + y * y)); //using dot product
	return 8 * atan(1) - acos(x / sqrtl(x * x + y * y)); // 2pi - alpha
}

int main(){
	ll x, y; cin >> x >> y;
	cout << setprecision(6) << fixed << angle(x, y);
	return 0;
}