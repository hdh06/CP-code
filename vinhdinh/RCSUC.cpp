#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll UCLN(ll a, ll b){
	if (a == 0) return b;
	return UCLN(b % a, a);
}

int main(){
	ll a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	cout << UCLN(a, b);
	return 0;
}