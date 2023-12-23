#include <bits/stdc++.h>

using namespace std;



int main(){
	string s; cin >> s;
	int m; cin >> m;
	while(m--){
		int k, u, v;
		cin >> u >> v >> k;
		u--, v--;
		reverse(s.begin() + u, s.begin() + v + 1);
		rotate(s.begin() + u, s.begin() + u + (k % (v - u + 1)),s.begin() + v + 1);
		reverse(s.begin() + u, s.begin() + v + 1);
	}	

	cout << s;
	return 0;
}