#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll x1, y1; cin >> x1 >> y1;
	ll x2, y2; cin >> x2 >> y2;
	
	cout << setprecision(6) << fixed << acos((x1 * x2 + y1 * y2) / sqrtl(x1 * x1 + y1 * y1) / sqrtl(x2 * x2 + y2 * y2));
	return 0;
}