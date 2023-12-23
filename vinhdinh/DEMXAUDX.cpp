#include <bits/stdc++.h>

using namespace std;

string convert(string s){
	string ans = "#";
	for (auto x: s) ans += x, ans += "#";
	return ans;
}

int main(){
	int n, q; cin >> n >> q;
	string s;
	cin >> s;	
	s = convert(s);

	n = s.size();

	vector<int> p(n, 0);

	for (int i = 0, l = 0, r = 0; i < n; i++){
		p[i] = min(0, max(r - i, p[l + r - i]));
		while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) 
			p[i]++;
		if (i + p[i] > r) r = i + p[i], l = i - p[i];
	}

	// for (auto x: s) cout << x << " "; cout << endl;
	// for (auto x: p) cout << x << " "; cout << endl;

	while (q--){
		int l, r; cin >> l >> r;
		l = 2*(l - 1) ;
		r = 2*(r - 1) + 2; 

		int tong = 0;
		for (int i = l; i <= r; i++){
			int d = min({r - i + 1, p[i], i - l + 1});
			tong += d/2;
		}
		cout << tong << "\n";
	}
	return 0;
}