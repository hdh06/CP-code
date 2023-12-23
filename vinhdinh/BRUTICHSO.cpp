#include <bits/stdc++.h>

using namespace std;

int num(char c){return c - '0';}

int main(){
	string s;
	cin >> s;

	int maxn = 0;

	if (s[0] == '1') maxn = pow(9, s.size() - 1);

	int tich = 1;

	for (int i = 0; i < s.length(); i++){
		if (s[i] != '0') maxn = max(maxn, (int)(tich*(num(s[i]) - 1))*(int)pow(9, s.size() - i - 1));
		//cout << tich << "*" << num(s[i]) - 1  << "*" << pow(9, s.size() - i - 1) << "="<< (tich*(num(s[i]) - 1))*(int)pow(9, s.size() - i - 1) << "\n";
		tich *= num(s[i]);
	}
	maxn = max(maxn, tich);
	cout << maxn;
	return 0;
}