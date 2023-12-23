#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q;
	cin >> n >> q;

	vector<long long> diff(n + 2, 0);	

	while(q--){
		int x, y, c;
		cin >> x >> y >> c;
		diff[x] += c;
		diff[y + 1] -= c;
	}

	long long num = 0;
	for (int i = 1; i <= n; i++){
		num += diff[i];
		cout << num << " ";
	}
	return 0;
}