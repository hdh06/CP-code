#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;	
	int a, b, c, d;
	a = b = c = d = -1;
	for (int i = 0; i < s.size(); i++){
		if (a == -1 && s[i] == 'A') a = i;
		if (b == -1 && s[i] == 'C') b = i;
		if (c == -1 && s[i] == 'G') c = i;
		if (d == -1 && s[i] == 'T') d = i;
		if (a != -1 && b != -1 && c != -1 && d != -1){
			cout << s[max({a, b, c, d})];
			a = b = c = d = -1;
		}
	}
	if (a == -1) cout << 'A';
	else if (b == -1) cout << 'C';
	else if (c == -1) cout << 'G';
	else cout << 'T';
	return 0;
}