#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll x, y, A, B, C; cin >> x >> y >> A >> B >> C;
	cout << setprecision(6) << fixed << 1.0L * abs(A * x + B * y + C) / sqrtl(A * A + B * B);	
	return 0;
}