#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	for (int b = 0; b < (1 << s.size()); b++){
		string ans;
		for (int i = s.size(); i >= 0; i++) if (b & (1 << i)){
			ans.push_back('(');
		}
	}	
	return 0;
}