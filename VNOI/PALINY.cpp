#include <bits/stdc++.h>

using namespace std;

string convert(string s){
	string ans = "#";
	for (auto x: s) ans += x, ans += "#";
	return ans;
}

vector<int> manacher(string s){
	s = '$' + s; s = s + '%';

	vector<int> p(s.size(), 0);

	for (int i = 1, l = 0, r = 0; i < s.size() - 1; i++){
		p[i] = max(0, min(r - i, p[l + r - i]));
		while (s[i + p[i]] == s[i - p[i]]) p[i]++;
		if (i + p[i] > r) l = i - p[i], r = i + p[i];
	}

	return vector<int>(p.begin() + 1, p.end() - 1);
}

int main(){
	int n; cin >> n;
	string s; cin >> s;

	s = convert(s);

	vector<int> p = manacher(s);

	cout << *max_element(p.begin(), p.end()) - 1;;
	return 0;
}