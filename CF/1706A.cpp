#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	string s(m, 'B');
	while (n--){
		int a; cin >> a;
		int x = a - 1, y = m - a + 1 - 1;
		if (x > y) swap(x, y);
		if (s[x] != 'A') s[x] = 'A';
		else s[y] = 'A';
	}
	cout << s << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}