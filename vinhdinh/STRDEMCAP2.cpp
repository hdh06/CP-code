#include <bits/stdc++.h>

using namespace std;

int const N = 256;

int fre[N] = {};

int main(){
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) fre[s[i]]++;

	long long dem = 0;
	for (int i = 0; i < N; i++) dem += fre[i]*(fre[i]-1)/2;

	cout << dem;
	return 0;
}