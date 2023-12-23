#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	while(n--){
		vector<int> arr(m);
		for (int i = 0; i < m; i++) cin >> arr[i];

		sort(arr.begin(), arr.end());

		for(auto i: arr) cout << i << " "; cout << endl;
	}

	return 0;
}