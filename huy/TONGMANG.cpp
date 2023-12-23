#include <bits/stdc++.h>

using namespace std;

int num(char x){
	return x - '0';
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
	int n;
	cin >> n;
	string tong = "0";
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		tong = tongstr(tong,s);
	}
	cout << tong;
	return 0;
}