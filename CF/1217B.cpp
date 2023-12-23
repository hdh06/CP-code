#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, x; cin >> n >> x;
	int a = -1, b = -1;
	for (int i = 1; i <= n; i++){
		int d, h; cin >> d >> h;
		if (d - h > 0) b = max(b, d - h);
		a = max(a, d);
	}	

	if (x <= a) cout << "1\n";
	else{ 
		if (b == -1) cout << "-1\n";
		else cout << (x - a + b - 1) / b + 1 << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}