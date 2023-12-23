#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;	

	int res = 0;

	map<int, int> m;

	for (int d = 1; d <= 50; d++){
		m.clear(); int ans;
		for (auto x: arr){
			auto k = m.find(x - d);
			if (k != m.end())
				ans = m[x] = k -> second + 1;
			else ans = m[x] = 1;
			res = max(res, ans);
		}
	}

	cout << res;
	return 0;
}
    