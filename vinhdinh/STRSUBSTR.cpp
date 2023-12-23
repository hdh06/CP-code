#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	char c = 'a';
	for (int i = 0; i < s.size(); i++) if (c != 'z' + 1){
		if (s[i] <= c) s[i] = c++;
	}	
	if (c != 'z' + 1) cout << -1;
	else cout << s;
	return 0;
}