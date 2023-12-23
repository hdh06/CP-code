#include <bits/stdc++.h>

using namespace std;

string const slp = "GSPVHCUTE";

int cnt[10];

int main(){
	map<char, int> m;
	for (int i = 0; i < 9; i++)
		cin >> m[slp[i]];

	int dem = 0;
	for (auto x: m) cnt[++dem] = x.second;

	for (int i = 1; i <= 9; i++) cout << cnt[i] << "\n";
	return 0;
}