#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool pc(ll n){
	if (n < 2) return false;
	for (ll i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;
	return true;
}

int main(){
	ll n; cin >> n;
	cout << (pc(n)?"YES":"NO");
	return 0;
}