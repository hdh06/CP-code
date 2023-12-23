#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n; 

	ll tong = 0, dem = 1;
	for (int i = 1; i <= n; i++){
		tong+= dem;
		dem+=3;
	}

	cout << tong << endl;

	tong = 0, dem = 1;
	for (int i = 1; i <= n; i++){
		cout << dem << " ";
		tong+= dem;
		dem+=3;

	}
	return 0;
}