#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int nim = 0;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			nim ^= x % 4;
		}
		cout << (nim?"first":"second") << "\n";
	}	
	return 0;
}