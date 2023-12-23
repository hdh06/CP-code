#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	int i = 0; bool flag = false;
	while (i < s.size() && s[i] == 'a') i++;
	while (i < s.size() && s[i] != 'a') s[i++]--, flag = true;
	if (!flag) s[s.size() - 1] = 'z';
	cout << s;	
	return 0;
}
