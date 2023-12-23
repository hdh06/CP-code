#include <bits/stdc++.h>

using namespace std;

string mahoa(string s, long long k){
	for (int i = 0; i < s.length(); i++){
		long long d = s[i];
		d -= 'A';
		d += k;
		d %= 26;
		d += 'A';
		s[i] = d;
	}
	return s;
}

int main(){
	string s; long long k;
	cin >> k >> s;
	cout << mahoa(s,k);
	return 0;
}