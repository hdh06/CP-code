#include <bits/stdc++.h>

//|-| |) |-|

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t --){
		string s;
		cin >> s;

		int a = 0, b = 0, c = 0;
		for (int i = 0; i < s.size(); i++){
			if ('A' <= s[i] && s[i] <= 'Z') a = 1;
			if ('a' <= s[i] && s[i] <= 'z') b = 1;
			if ('0' <= s[i] && s[i] <= '9') c = 1;
		}	

		int ans = min(5, max((int)s.size() - 5, 0));
		if (a + b + c == 1) ans += 1;
		if (a + b + c == 2) ans += 2;
		if (a + b + c == 3) ans += 5;

		cout << ans << " ";
	}	
	return 0;
}