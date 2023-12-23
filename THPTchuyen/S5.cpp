#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	string rs = s;
	reverse(rs.begin(), rs.end());

	cout << (rs == s? "YES": "NO");	
	return 0;
}