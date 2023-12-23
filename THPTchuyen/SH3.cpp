#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;

	int dem = 0;

	for (int i = 1; i <= sqrt(n); i++) if (n % i == 0){
		dem += 2 - (i * i == n);
	}

	cout << dem;
	return 0;
}