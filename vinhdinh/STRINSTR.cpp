#include <bits/stdc++.h>

using namespace std;

vector<int> z(string s){
	vector<int> z(s.size(), 0);
	for (int i = 1, x = 0, y = 0; i < s.size(); i++){
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) 
			x = i, y = i + z[i], z[i]++;
	}
	return z;
}

int main(){
	string s, k;
	cin >> s >> k;

	vector<int> zf = z(k + '#' + s);

	// for (auto x: k) cout << x << " "; cout << "# ";
	// for (auto x: s) cout << x << " "; cout << endl;
	// for (auto x: zf) cout << x << " "; cout << '\n';

	int dem = 0;
	for (int i = k.size() + 1; i < zf.size(); i++)
		if (zf[i] != 0 && i + zf[i] < zf.size()) dem++;
	
	cout << dem;
	return 0;
}