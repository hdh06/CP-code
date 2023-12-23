#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int tong = INT_MAX;
	while (n--){
		int t; cin >> t;
		if (t & 1) tong = min(tong, t);
	}	

	cout << tong;
	return 0;
}