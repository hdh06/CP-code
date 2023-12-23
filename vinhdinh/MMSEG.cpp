#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> arr(n + 1);	
	int maxx = INT_MIN, minn = INT_MAX;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		maxx = max(maxx, arr[i]);
		minn = min(minn, arr[i]);
	}
	
	int max_pos = -1, min_pos = -1;
	
	int ans = INT_MAX;
	for (int i = 1; i <= n; i++){
		if (arr[i] == maxx){
			if (min_pos != -1) ans = min(ans, i - min_pos + 1);
			max_pos = i;
		}
		if (arr[i] == minn){
			if (max_pos != -1) ans = min(ans, i - max_pos + 1);
			min_pos = i;
		}
	}
	cout << ans;
	return 0;
}