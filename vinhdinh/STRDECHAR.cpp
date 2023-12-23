#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int main(){
	string s, t; cin >> s >> t;

	bool pre[N] = {}, suf[N] = {};

	s = ' ' + s + ' ';
	t = ' ' + t + ' ';

	pre[0] = suf[0] = pre[s.size() - 1] = suf[s.size() - 1] = 1;

	for (int i = 1; i < s.size() - 1; i++) if (s[i] == t[i]) pre[i] |= pre[i - 1];	
	for (int i = s.size() - 2; i >= 2; i--)
		if (s[i] == t[i - 1]) suf[i] |= suf[i + 1];

	vector<int> ans;

	// for (int i = 0; i < s.size(); i++) cout << pre[i] << " \n"[i == s.size() - 1];
	// for (int i = 0; i < s.size(); i++) cout << suf[i] << " \n"[i == s.size() - 1];	

	for (int i = 1; i < s.size() - 1; i++){
		if (pre[i - 1] && suf[i + 1]) ans.push_back(i);
	}

	cout << ans.size() << endl;
	for (auto x: ans) cout << x << " ";
	return 0;
}