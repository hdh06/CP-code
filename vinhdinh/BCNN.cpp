#include <bits/stdc++.h>

using namespace std;

int main(){
	unsigned long long a, b , lcm, gcd;
	cin >> a >> b;

	gcd = __gcd(a, b);
	lcm = (a/gcd)*b;
	cout << lcm;
	return 0;
}