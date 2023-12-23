#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	vector<array<int,2> > p;

	for (int i = 1; i <= m; i++){
		int l, r;
		cin >> l >> r;
		if (l <= r){
			p.push_back({l, + 1});
			p.push_back({r + 1, -1});
		}
		else{
			p.push_back({l, +1}); p.push_back({n + 1, -1});
			p.push_back({1, +1}); p.push_back({r + 1, -1});
		}
	}

	sort(p.begin(), p.end());

	int d = p[0][1], maxd = 0, maxs = 0;
	for (int i = 1; i < p.size(); i++){
		if (maxd < d){
			maxd = d;
			maxs = 0;
		}
		if (maxd == d){
			maxs += p[i][0] - p[i - 1][0];
		}
		d += p[i][1];
	}

	cout << maxd << " " << maxs;
	return 0;
}