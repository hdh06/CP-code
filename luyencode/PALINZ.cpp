#include <bits/stdc++.h>

//|-| |) |-|

using namespace std;

int main(){
	string s;
	cin >> s;

	s = ' ' + s;

	int t; cin >> t;
	while(t--){
		int l, r;
		cin >> l >> r;

		bool flag = true;
		for (int i = l, j = r; i < j; i++, j--){	
			if (s[i] != s[j]) flag = false;
		}

		if (flag) cout << "YES";
		else cout << "NO";
		cout << endl;
	}	
	return 0;
}