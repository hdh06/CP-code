#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int x; cin >> x;
		int a = 0, b = 0;
		for (int i = 2; i <= n; i++){
			cin >> x;
			if (i & 1) b ^= x;
			else a ^= x;
		}
		cout << (a?"first\n":"second\n");
	}	
	return 0;
}