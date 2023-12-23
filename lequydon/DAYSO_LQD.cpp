#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll n){
	return n * (n - 1) + 1;
}

int main(){
	int n; cin >> n;
	ll v = sqrtl(f(n)) * sqrtl(f(n + 1)) + 1;
	cout << v;
	return 0;
}