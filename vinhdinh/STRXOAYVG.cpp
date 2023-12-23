#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	char c = 'a';

	int tong = 0;
	for (int i = 0; i < s.size(); i++){
		int ans = INT_MAX;
		ans = min(ans, abs(s[i] - c));
		ans = min(ans, c - 'a' + 'z' - s[i] + 1);
		ans = min(ans, 'z' - c + 1 + s[i] - 'a');
		// cout << ans << " ";
		tong += ans;
		c = s[i];
	}	

	cout << tong;
	return 0;
}