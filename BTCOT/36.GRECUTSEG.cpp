#include <bits/stdc++.h>

using namespace std;

int main(){
	unordered_map<int, int> mymap;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int r = 0;
		for (int i = 1; i <= n; i++){
			int temp;
			cin >> temp;
			if (r < mymap[temp]){
				if (r != 0) cout << r << '\n';
				cout << r + 1 << " ";
				r = i;
			}
			else mymap[temp] = i;
		}

		if (r == 0){
			cout << -1 << '\n';
		}
		else cout << n << '\n';
		mymap.clear();
	}

	return 0;
}
    