#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; 
	cin >> s;

	s = s + (char)('z' + 1);

	for (int i = 0; i < s.size() - 2; i++){
		if (s[i] == s[i + 1]){
			s[i + 1] = max(s[i], s[i + 2]) + 1;
			if (s[i + 1] > 'z') s[i + 1] = min(s[i], s[i + 2]) - 1;
			if (s[i + 1] < 'a') s[i + 1] = 'h';
		}
	}	

	s.erase(s.end() - 1);

	cout << s;
	return 0;
}