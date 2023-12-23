#include <bits/stdc++.h>

using namespace std;

int num(char c){
	return c - '0';
}

string cong(string a, string b){
	if (a.size() > b.size()) swap(a, b);
	while (a.size() < b.size()) a = '0' + a;

	string c = a;
	int n = a.size(), tong = 0;
	for (int i = n - 1; i >= 0; i--){
		tong += num(a[i]) + num(b[i]);
		c[i] = tong % 10 + '0';
		tong/=10;
	}
	if (tong != 0) c = (char)(tong + '0') + c;
	return c;
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << cong(a, b);
	return 0;
}