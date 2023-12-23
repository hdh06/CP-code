#include <bits/stdc++.h>

using namespace std;

#define file "volleyball"

int main(){
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	int t; cin >> t;
	while (t--){
		int k, x, y; cin >> k >> x >> y;
		cout << min(max(0, max(k, y + 2) - x), max(0, max(k, x + 2) - y)) << " ";
	}//_OS
	return 0;
}