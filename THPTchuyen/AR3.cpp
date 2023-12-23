#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int tong = 0;
	while (n--){
		int t; cin >> t;
		tong += (t % 3 == 0);
	}	

	cout << tong;
	return 0;
}