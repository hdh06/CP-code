#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll UCLN(ll a, ll b){
	if (a == 0) return b;
	return UCLN(b % a, a);
}

int main(){
	ll a, b, c, d;	
	cin >> a >> b >> c >> d;
	cout << UCLN(a, UCLN(b, UCLN(c,d)));
	return 0;
}