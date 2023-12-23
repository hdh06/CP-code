#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int minn = INT_MAX;
	while(n--){
		int t; cin >> t;
		minn = min(minn, t);
	}	

	cout << minn;
	return 0;
}