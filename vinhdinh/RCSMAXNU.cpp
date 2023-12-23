#include <bits/stdc++.h>

using namespace std;

int num(char c){return c - '0';}

int tk(string s, int n){
	if (n == -1) return 0;
	return max(num(s[n]),tk(s, n - 1));
}

int main(){
	string s;
	cin >> s;	

	cout << tk(s, s.size() - 1);
	return 0;
}