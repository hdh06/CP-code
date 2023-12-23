#include <bits/stdc++.h>

using namespace std;

int const N = 5001;

int num(char c){
	return c - '0';
}

int p(char a, char b){
	return num(a)*10 + num(b);
}

string tong(string a, string b){
	if (a.size() > b.size()) swap(a, b);
	while (a.size() < b.size()) a = '0' + a;
	
	string c; 
	int n = a.size();

	int x = 0;
	for (int i = n - 1; i >= 0; i--){
		x += num(a[i]) + num(b[i]);
		c = (char)(x%10 + '0') + c;
		x/=10;
	}
	if (x != 0) c = (char)(x + '0') + c;
	return c;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	string dp[N] = {};
	while(1){
		getline(cin, s);
		if (s[0] == '0') return 0;

		int n = s.length();

		dp[n] = "1";
		dp[n - 1] = "1";

		if (s[n - 1] == '0') dp[n - 1] = "0";

		for (int i = n - 2; i >= 0; i--){
			if (s[i] == '0') dp[i] = "0";
			else
			if(p(s[i], s[i + 1]) <= 26){
				dp[i] = tong(dp[i + 1], dp[i + 2]);
			}
			else{
				dp[i] = dp[i + 1];
			}
		}

		cout << dp[0] << endl;
	}
	return 0;
}