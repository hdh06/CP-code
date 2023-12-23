#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b){
	return a / __gcd(a, b) * b;
}

int main(){
	long long a, b, c, d; cin >> a >> b >> c >> d;
	cout << b - a + 1 - (b / c - (a - 1) / c) - (b / d - (a - 1) / d) + (b / lcm(c, d) - (a - 1) / lcm(c, d));
	return 0;
}