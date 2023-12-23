#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll a, b; cin >> a >> b;
	cout << (a*a + 2*a*b + b*b)/(a + b);
	return 0;
}