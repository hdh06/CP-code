#include <bits/stdc++.h>

using namespace std;

int num(char c){ return c - '0';}

int dem(string s, int n){
	if (n == -1) return 0;
	return (num(s[n]) % 2) + dem(s, n - 1);
}

int main(){
	string s;
	cin >> s;

	cout << dem(s, s.size() - 1);
	return 0;
}