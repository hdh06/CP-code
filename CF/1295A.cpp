#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	if (n & 1){
		cout << 7;	
		n -= 3;
	}
	n /= 2;
	while (n--)cout << 1;
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}