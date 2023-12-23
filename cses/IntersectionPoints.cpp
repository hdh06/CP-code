#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<int, 4> iiii; //tu quy i

vector<iiii> event;

int const N = 2e6 + 1;
int const D = 1e6;

ll tree[N] = {};

void upd(int x, int v){
	for (int i = x; i < N; i += (i & -i)) tree[i] += v;
}

int get(int x){
	ll tong = 0;
	for (int i = x; i >= 1; i -= (i & -i)) tong += tree[i];
	return tong;
}

int main(){
	int n; cin >> n;
	for (int i = 1, x1, y1, x2, y2; i <= n; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 == y2){
			event.push_back({x1, 1, y1, y2});
			event.push_back({x2, 3, y1, y2});
		}
		else{
			event.push_back({x1, 2, y1, y2});
		}
	}	

	sort(event.begin(), event.end());

	ll ans = 0;

	for (auto x: event){
		if (x[1] == 1) upd(x[2] + D, +1);
		if (x[1] == 2) ans += get(x[3] + D) - get(x[2] + D - 1);
		if (x[1] == 3) upd(x[2] + D, -1);
	}

	cout << ans;
	return 0;
}