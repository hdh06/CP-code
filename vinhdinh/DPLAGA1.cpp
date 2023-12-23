#include <bits/stdc++.h>

using namespace std;

int num(char c){
	return c - '0';
}

string tongstr(string a, string b){
	if (a.size() > b.size()) swap(a, b);
	while (a.size() < b.size()) a = '0' + a;
	int memo = 0;
	string c;
	for (int i = a.size() - 1; i >= 0; i--){
		int x = num(a[i]) + num(b[i]) + memo;
		memo = x / 10;
		c = (char)((x % 10) + '0') + c;
	}
	if (memo != 0) c = (char)(memo + '0') + c;
	return c;
}

int main(){
	string f[210];

	f[0] = "1";
	f[1] = "1";

	for (int i = 2; i <= 200; i ++){
		f[i] = tongstr(f[i - 1], f[i - 2]);
	}

	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}