#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;

	s = s + ' ';

	int dem = 0;

	for (int i = 0; i < n; i += 2){
		if (s[i] == s[i + 1]){
			s[i] = 'a';
			s[i + 1] = 'b';
			dem++;
		}
	}	

	s.erase(s.end() - 1);

	cout << dem << "\n" << s;
	return 0;
}