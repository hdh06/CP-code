#include <bits/stdc++.h>

using namespace std;

vector<int> manacher_odd(string s){
	s = '!' + s; s = s + '&';
	int n = s.size();

	vector<int> p(n, 0);
	for (int i = 1, l = 0, r = 0; i < n - 1; i++){
		p[i] = max(0, min(r - i, p[l + r - i]));
		while (s[i + p[i]] == s[i - p[i]]) p[i]++;
		if (i + p[i] > r) r = i + p[i], l = i - p[i];
	}
	return vector<int>(p.begin() + 1, p.end() - 1);
}

string convert(string s){
	string ans = "#";
	for (auto x: s) ans += x, ans += "#";
	return ans;
}

int main(){
	string s; cin >> s;

	s = convert(s);

	vector<int> p = manacher_odd(s);
	
	int maxn = 0, maxp = -1;
	for (int i = 0; i < s.size(); i++)
		if (p[i] > maxn){
			maxn = p[i];
			maxp = i;
		}	

	for (int l = maxp - p[maxp] + 1; l < maxp + p[maxp]; l++) if (s[l] != '#') cout << s[l]; 
	return 0;
}