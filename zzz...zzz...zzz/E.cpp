#include <bits/stdc++.h>

using namespace std;

vector<int> zfunc(string s){
	int n = s.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++){
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			l = i, r = i + z[i], z[i]++;
	}
	return z;
}

int main(){
	string s; cin >> s;
	int n = s.size();
	vector<int> z = zfunc(s);
	vector<int> cnt(n + 1);

	for (int i = 0; i < n; i++) cnt[z[i]]++;
	for (int i = n - 1; i >= 0; i--) cnt[i] += cnt[i + 1];
	vector<pair<int, int> > ans;
	for (int i = n - 1; i >= 0; i--)
		if (i + z[i] == n)
			ans.push_back({z[i], cnt[z[i]] + 1});
	ans.push_back({n, 1});
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x.first << " " << x.second << "\n";
	return 0;
}