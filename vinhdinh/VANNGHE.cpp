#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, m;
	cin >> n >> m;

	long long gcd = __gcd(n, m);

	cout << "So to: " << gcd << endl;
	cout << "So nam moi to: " << n/gcd << endl;
	cout << "So nu moi to: " << m/gcd;	
	return 0;
}