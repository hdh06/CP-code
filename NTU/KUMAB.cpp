#include <bits/stdc++.h>

using namespace std;

int main(){
	string s = "~ ! ~ ! ~ ! ~";
	for(int i = 0; i < s.size(); i++){
		cout << (char)(s[i] & s[i - 1]) << '\n';
	}	
	return 0;
}