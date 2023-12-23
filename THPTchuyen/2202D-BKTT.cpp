#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	int k; cin >> k;
	char c = *min_element(s.begin(), s.end());
	if (k > n){
		cout << s;
		for (int i = 1; i <= k - n; i++)
			cout << c;
	}else{
		char m = *max_element(s.begin(), s.end());
		int i = min((int)s.size() - 1, k - 1);
		while (s[i] == m) i--;
		char t = 'z' + 1;
		for (auto x: s) if (x > s[i]) t = min(t, x);
		s[i] = t;
		cout << s.substr(0, i + 1);
		for (int j = i + 1; j < min(k, (int)s.size()); j++){
			cout << c;
		}
	}
	return 0;
}