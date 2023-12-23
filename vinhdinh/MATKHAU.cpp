#include <bits/stdc++.h>

using namespace std;

vector<int> z(string s){
	vector<int> z(s.size());
	for (int i = 1, x = 0, y = 0; i < s.size(); i++){
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
			x = i, y = i + z[i], z[i]++;
	}
	return z;
}

int main(){
	string s; cin >> s;

	vector<int> zf = z(s);

	string ans;

	for (int i = 0; i < zf.size(); i++){
		if (i + zf[i] == s.size() && i <= zf[i]){
			ans = s.substr(0, i);
			break;
		}
	}

	if (ans.empty()) ans = s;

	// for (auto x: s) cout << x << " "; cout << endl;
	// for (auto x: zf) cout << x << " "; cout << endl;

	int fre[26] = {};
	for (auto x: ans) fre[x - 'a']++;
	cout << *max_element(fre, fre + 26);
	return 0;
}