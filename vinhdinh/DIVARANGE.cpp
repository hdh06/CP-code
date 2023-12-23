#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll BCNN(ll a, ll b){
	return a/__gcd(a, b)*b;
}

int main(){
	ll n, l, r;
	cin >> n >> l >> r;

	ll bcnn, tich = 1;
	cin >> bcnn;
	tich = bcnn;

	for(int t = n - 1;t--;){
		ll temp;
		cin >> temp;
		bcnn = BCNN(bcnn, temp); 
	}	

	cout << r/bcnn - (l - 1)/bcnn;
	return 0;
}