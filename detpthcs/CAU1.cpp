#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	ll a = n / 3, b = n / 9;
	cout << 3*a*(a+1)/2 - 9*b*(b+1)/2;
	return 0;
}