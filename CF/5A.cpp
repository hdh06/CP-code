#include <bits/stdc++.h>

using namespace std;

int main(){
	// freopen("inp.inp", "r", stdin);
	string s;
	int ans = 0;
	int dem = 0;
	while (getline(cin, s)){
		if (s[0] == '+') dem++;
		else if (s[0] == '-') dem--;
		else{
			int i = 0;
			while (s[i] != ':') i++;
			ans += dem * (s.size() - i - 1);
		}
	}
	cout << ans;
	return 0;
}