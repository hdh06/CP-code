#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e6 + 1;

bool sang[N] = {1, 1};
array<int, 2> td[N];

void init(){
	for (ll i = 2; i < N; i++) if (!sang[i])
		for (ll j = i * i; j < N; j += i) sang[j] = true;

	int x = 0, y = 0;
	int dx = 1, dy = 0, dem = 1;

	for (int i = 3; i < N; i++) if (!sang[i]){
		if (dx != 0){
			int dau = (dx > 0? +1: -1);
			x = x + dau;
			dx = dx - dau;
			if (dx == 0) dy = (dem++)*dau;
		}
		else{
			int dau = (dy > 0? +1: -1);
			y = y + dau;
			dy = dy - dau;
			if (dy == 0) dx = dem*(- dau);
		}
		td[i] = {x, y};
	}
}

int main(){
	init();
	int n; cin >> n;
	cout << td[n][0] << " " << td[n][1];
	return 0;

}