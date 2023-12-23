#include <bits/stdc++.h>

using namespace std;

vector<int> zfunc(string s){
	int n = s.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++){
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) l = i, r = i + z[i], z[i]++;
	}
	return z;
}

int main(){
	string s; cin >> s;
	string p; cin >> p;
	string t = p + "#" + s;
	vector<int> z = zfunc(t);
	int ans = 0;

	for (int i = p.size() + 1; i < s.size() + p.size() + 1; i++)
		ans += (z[i] == p.size());
	cout << ans;
	return 0;
}