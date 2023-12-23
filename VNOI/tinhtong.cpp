#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int tong = 0;
	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		tong += t;
	}	

	cout << tong;
	return 0;
}