#include <bits/stdc++.h>

using namespace std;

string nen(string s){
	s += ' ';
	int cur = 1;
	string ans;
	for (int i = 1; i < s.length(); i++){
		if (s[i] != s[i - 1]){
			string num;
			while (cur > 0){
				num.push_back(cur % 10 + '0');
				cur /= 10;
			}
			reverse(num.begin(),num.end());
			ans += num;
			ans.push_back(s[i - 1]);
			cur = 1;
		}
		else cur ++;
	}
	return ans;
}

int num(char c){
	return c - '0';
}

string gnen(string s){
	string ans; int tong = 0;
	for (int i = 0; i < s.length(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			tong = tong * 10 + num(s[i]);
		}
		else{
			for (int j = 0; j < tong; j++) ans.push_back(s[i]);
			tong = 0;
		} 
	}
	return ans;
}

int main(){
	string a, b;
	cin >> a >> b;

	cout << nen(a) << endl << gnen(b);
	return 0;
}