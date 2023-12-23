#include <bits/stdc++.h>

using namespace std;

bool checkP(int n){
	if (n < 2) return false;

	for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;

	return true;
}

int main(){
	string s;
	getline(cin, s);

	int f[300] = {};
	for (int i = 0; i < s.size(); i++) f[s[i]]++;

	int dem = 0;

	for (int i = 0; i < 300; i++) if (checkP(f[i])) dem += f[i];

	cout << dem;
	return 0;
}