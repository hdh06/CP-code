#include <bits/stdc++.h>

using namespace std;

int fmax(string s){
	int ans = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] > s[ans]) ans = i;
	}
	return ans;
}

int main(){
	string s; cin >> s;
	int k; cin >> k;
	string ans;
	while (k > 0 && s.size() > 0){
		int p = fmax(s.substr(0, min(s.size(), k)));
		if (p <= k){
			k -= p;
			ans.push_back()
		}
	}

	cout << ans << s;
	return 0;
}