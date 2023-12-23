#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s;
	cin >> s;

	string ans;
	if (n % 2 != 0) ans = ans + s[0]; 
	for (int i = n % 2; i < n; i+=2){
		ans = ans + s[i + 1];
		ans = s[i] + ans;
	}

	cout << ans;
	return 0;
}