#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;

bool cot[N] = {};
bool hang[N] = {};

int main(){
	int n, m; cin >> n >> m;
	ll left =n*1LL*n;
	ll c = 0, h = 0;
	while (m--){
		int x, y;
		cin >> x >> y;
		ll tong = 0;

		if (!hang[x]){
			hang[x] = true;
			tong += n - c;
			h++;
		}

		if (!cot[y]){
			cot[y] = true;
			tong += n - h;
			c++;
		}

		left -= tong;
		cout << left << " ";
	}	
	return 0;
}