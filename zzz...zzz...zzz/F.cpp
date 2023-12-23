#include <bits/stdc++.h>

using namespace std;

vector<int> zfunc(vector<int> s){
	int n = s.size();
	vector<int> z(n);
	vector<int> diff(n);
	for (int i = 1; i < n; i++)
		diff[i] = s[i] - s[i - 1];
	// for (auto x: s) cout << x << " "; cout << "\n";
	// for (auto x: diff) cout << x << " "; cout << "\n";
	for (int i = 1, l = 0, r = 0; i < n; i++){
		z[i] = max(0, min(z[i - l], r - i + 1));
		if (z[i] == 0) z[i]++;
		while (i + z[i] < n && diff[z[i]] == diff[i + z[i]])
			l = i, r = i + z[i], z[i]++;
	}
	// for (auto x: z) cout << x << " "; cout << "\n";
	return z;
}

int main(){
	int n, m; cin >> n >> m;
	vector<int> s(n), p(m);
	for (auto &x: s) cin >> x;
	for (auto &x: p) cin >> x;
	vector<int> t = p;
	t.push_back(-1000000001);
	for (auto x: s) t.push_back(x);

	vector<int> z = zfunc(t);

	int ans = 0;
	for (int i = m + 1; i < n + m + 1; i++)
		ans += (z[i] == m);
	
	cout << ans;
	return 0;
}