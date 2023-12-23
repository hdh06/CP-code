#include <bits/stdc++.h>

using namespace std;

bool check(int x){
	int last = -1;
	while (x > 0){
		if (last == x % 10) return false;
		last = x % 10;
		x /= 10;
	}
	return true;
}

int main(){
	int l, r; cin >> l >> r;
	int ans = 0;
	for (int i = l; i <= r; i++) if (check(i) && i % 17 == 0) ans++;
	cout << ans << "\n";
	return 0;
}