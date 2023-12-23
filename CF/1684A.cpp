#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	if (n < 100) cout << n % 10 << "\n";	
	else{
		int minn = 10;
		while (n > 0){
			minn = min(minn, n % 10);
			n /= 10;
		}
		cout << minn << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}