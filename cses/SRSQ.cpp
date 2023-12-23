#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> sums(n + 1, 0);
	for (int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		sums[i] = sums[i-1] + temp;
	}

	while(q--){
		int a, b;
		cin >> a >> b;
		cout << sums[b] - sums[a - 1] << endl;
	}
	return 0;
}