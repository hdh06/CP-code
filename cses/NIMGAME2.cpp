#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int tong = 0;
		for (int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			tong ^= temp;
		}
		if (tong != 0) cout << "first" << endl;
		else cout << "second" << endl;
	}
	return 0;
}