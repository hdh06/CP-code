#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int main(){
	int k; cin >> k;
	string s; cin >> s;

	int n = s.size();

	s = ' ' + s;

	int f[N] = {};

	for (int i = 1; i <= n; i++) 
		f[i] = f[i - 1] + (s[i] == '1');

	int dem = 0;

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) if (f[j] - f[i - 1] == k) dem++;
	
	cout << dem;
	return 0;
}