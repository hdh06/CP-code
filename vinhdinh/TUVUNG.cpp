#include <bits/stdc++.h>

using namespace std;

bool check(char c){
	return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' );
}

int const N = 1e6 + 1;

int main(){
	string s;
	cin >> s;

	s = '#' + s;
	int L[N] = {}, R[N] = {};

	for (int i = 1; i < s.size(); i++) L[i] = L[i - 1] + !check(s[i]);
	for (int i = s.size() - 1; i >= 1; i--) R[i] = R[i + 1] + !check(s[i]);

	long long tong = 0;

	for (int i = 1; i < s.size(); i++){
		if (check(s[i])){
			tong += L[i] + R[i];
		}
	}

	cout << tong;
	return 0;
}