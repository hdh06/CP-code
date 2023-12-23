#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i ++){
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end(), greater<int>());

		int k = arr[1] - 1;
		cout << min(k, n - 2) << endl;
	}
	return 0;
}