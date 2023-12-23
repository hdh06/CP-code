#include <bits/stdc++.h>

using namespace std;

void solve(){
	int x; cin >> x;
	int ans = 1;
	for (int i = 2; i <= sqrt(x); i++){
		int dem = 0;
		while (x % i == 0){
			dem++;
			x /= i;
		}
		ans *= (dem + 1);
	}
	if (x > 1) ans *= 2;
	cout << ans << "\n";
}

int main(){
	int t; cin >> t;
	while (t --) solve();
	return 0;
}