#include <bits/stdc++.h>

using namespace std;

struct P{
	int x, y, num;
	P(){}
	P(int x, int y, int num) : x(x), y(y), num(num) {}
};

int dis(P a, P b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(){
	int k, r; cin >> k >> r;
	int m; cin >> m;
	vector<P> loc(m);
	for (auto &x: loc)
		cin >> x.x >> x.y;
	int n; cin >> n;
	vector<P> h(n);
	for (auto &x: h)
		cin >> x.x >> x.y >> x.num;
	
	vector<int> inR(n);
	for (int j = 0; j < n; j++){
		P e = h[j];
		for (int i = 0; i < m; i++)
			if (dis(loc[i], e) <= r * r)
				inR[j] |= 1 << i;
	}
	
	int ans = 0;
	for (int mask = 0; mask < (1 << m); mask++){
		if (__builtin_popcount(mask) != k) continue;
		
		int res = 0;
		for (int i = 0; i < n; i++)
			if (mask & inR[i]) res += h[i].num;
		
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}