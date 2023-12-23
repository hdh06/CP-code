#include <bits/stdc++.h>

using namespace std;

int val(char c){
	if (c == '6' || c == '9') return 6;
	if (c == '2' || c == '5') return 2;
	return c - '0';
}

int main(){
	string s; cin >> s;
	string p; cin >> p;

	int fre[9] = {};

	for (auto x: p) fre[val(x)]++;

	int dem = 0;

	while (true){
		for (int i = 0; i < s.size(); i++)
			if (fre[val(s[i])] > 0) fre[val(s[i])]--;
			else{
				cout << dem;
				return 0;
			}
		dem++;
	}
	cout << dem;
	return 0;
}