#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q;
	cin >> n >> q;

	vector<long long> sum(n + 1, 0);

	for (int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		sum[i] = temp + sum[i - 1];
	}	

	while (q--){
		int l ,r;
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << endl;
	}
	return 0;
}