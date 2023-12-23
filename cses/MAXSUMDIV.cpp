#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;

	cout << (n/a)*x + (n/b)*y - n/(a/gcd(a, b)*b)*min(x, y);
	return 0;
}