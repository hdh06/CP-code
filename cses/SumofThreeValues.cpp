#include <bits/stdc++.h>

using namespace std;

typedef array<long long, 2> ii;

int main(){
	int n; long long x; cin >> n >> x;
	vector<ii> arr(n); 
	for (int i = 0; i < n; i++){
		cin >> arr[i][0];
		arr[i][1] = i + 1;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++){
			ii f = {x - arr[i][0] - arr[j][0], 0LL};
			int k = lower_bound(arr.begin() + j + 1, arr.end(), f) - arr.begin();
			if (k == n) continue;
			if (arr[i][0] + arr[k][0] + arr[j][0] == x){
				cout << arr[i][1] << " " << arr[j][1] << " " << arr[k][1];
				return 0;
			}
		}	
	cout << "IMPOSSIBLE";
	return 0;
}