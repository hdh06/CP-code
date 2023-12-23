#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int ad(int n, int pre){
	if (pre){
		return n;
	}
	return -n;
}

int main(){
	string s;
	cin >> s;
	ull n = 0, tong = 0;
	bool pre = 1;
	s = s + '+';
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '+'){
			tong += ad(n, pre);
			pre = 1;
			n = 0;
		}
		else if (s[i] == '-'){
			tong += ad(n,pre);
			pre = 0;
			n = 0;
		}
		else{
			n = n * 10 + (s[i] - '0');
		}
	}
	cout << tong;
	return 0;
}