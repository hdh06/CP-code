#include <bits/stdc++.h>

using namespace std;

int num(char c){return c - '0';}

int main(){
	string s;
	cin >> s;

	long long dem = 0;
	for (int i = 0; i < s.length(); i++) if(num(s[i]) % 2 == 0) dem += (i + 1);
	cout << dem;
	return 0;
}