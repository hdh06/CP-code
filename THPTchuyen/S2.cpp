#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	char c; cin >> c;

	cout << count(s.begin(), s.end(), c);	
	return 0;
}