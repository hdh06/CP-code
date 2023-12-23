#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q; cin >> n >> q;
	vector<int> px(n + 1, 0);
	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		px[i] = px[i - 1] ^ t;
	}

	while (q--){
		int a, b; cin >> a >> b;
		cout << (px[a - 1] ^ px[b]) << "\n";
	}
	return 0;
}