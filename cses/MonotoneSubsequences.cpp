#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		if (k == 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		vector<int> arr(n + 1);
		for (int i = 1; i <= n; i++) arr[i] = i;
		for (int i = k; i <= n; i += k) if (i + 1 < n) 
			swap(arr[i], arr[i + 1]);
		for (int i = 1; i <= n; i++) 
			cout << arr[i] << " \n"[i == n];
	}	
	return 0;
}