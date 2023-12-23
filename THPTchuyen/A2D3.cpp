#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int maxt = 0;
	for (int i = 1; i <= n; i++){
		int tong = 0;
		for (int j = 1; j <= n; j++){
			int t; cin >> t; tong += t;
		}
		maxt = max(maxt, tong);
	}	
	cout << maxt;
	return 0;
}