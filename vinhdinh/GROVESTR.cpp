#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	sort(s.begin(), s.end(), greater<char>());	

	string ans; bool w = 1;
	for (auto x: s){
		if (w) ans = x + ans;
		else ans = ans + x;
		w = !w;
	}

	cout << ans;
	return 0;
}