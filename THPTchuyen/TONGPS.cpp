#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b, c, d;
	cin >> a >> b >> c >> d;	

	long long m = (a*d + b*c), t = b*d;

	cout << m/__gcd(m, t) << " " << t/__gcd(m, t);
	return 0;
}