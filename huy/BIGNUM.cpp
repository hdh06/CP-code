#include <bits/stdc++.h>

using namespace std;

int num(char x){
	return x - '0';
}

l

string hieustr(string a, string b){
	bool kt = lexicographical_compare(a.begin(),a.end(),b.begin(),b.end());
	if (kt) swap(a, b);
	//cout << a << " " << b << endl;
	while (b.size() < a.size()) b = '0' + b;
	int memo = 0;
	string c;
	for (int i = a.size() - 1; i >= 0; i--){
		int x = num(a[i]) - num(b[i]) - memo;
		if (x >= 0){
			memo = 0;
			c = (char)(x + '0') + c;	
		} 
		else{
			memo = 1;
			c = (char)(10 + x + '0') + c;
		}
		//cout << x << " " << c << endl;
	}
	while (c[0] == '0') c.erase(0,1);
	if (kt) c = '-' + c;
	if (c == "") c = "0";
	return c;
}

string nhanstr(string a, string b){
	string c = "0";
	while(b != "0"){
		c = tongstr(a,c);
		b = hieustr(b,"1");
	}
	return c;
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << tongstr(a,b) << endl;
	cout << hieustr(a,b) << endl;
	cout << nhanstr(a,b);
	// string a = "123123", b = "123134";

	// cout << lexicographical_compare(a.begin(),a.end(),b.begin(),b.end()) << endl;
	return 0;
}
