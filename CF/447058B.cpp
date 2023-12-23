#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int arr[N];

int main(){
	int t; cin >> t;
	while (t--){
		int n, q; cin >> n >> q;
		for (int i = 1; i <= n; i++)	
			cin >> arr[i];
			
		int maxx = *max_element(arr + 1, arr + n + 1);
	
		while (q--){
			int type; cin >> type;
			if (type == 1){
				int pos, x; cin >> pos >> x;
				arr[pos] += x;
				maxx = max(maxx, arr[pos]);
			}
			if (type == 2){
				cout << maxx << "\n";
			}
		}
	}	
	return 0;
}