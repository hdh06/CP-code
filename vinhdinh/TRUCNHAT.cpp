#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int lcm = m*n/__gcd(n, m);

	cout << lcm << endl;
	cout << "An: " << lcm/n << endl;
	cout << "Bach: " << lcm/m;	
	return 0;
}