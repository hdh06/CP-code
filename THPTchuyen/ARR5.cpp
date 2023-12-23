#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int dem = 0;
	while(n--){
		int t; cin >> t;
		dem += (500 <= t && t <= 3000);
	}	

	cout << dem;
	return 0;
}