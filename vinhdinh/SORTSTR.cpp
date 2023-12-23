#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	string H, T;
	for (int i = 0; i < s.size(); i++){
		if ('A' <= s[i] && s[i] <= 'Z') H.push_back(s[i]);
		else T.push_back(s[i]);
	}	

	sort(H.begin(), H.end(), greater<char>());
	sort(T.begin(), T.end(), greater<char>());

	cout << H << T;
	return 0;
}