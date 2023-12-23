#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("inp.inp", "r", stdin);
	int n, s;
	cin >> n >> s;

	vector<ii> arr(n);

	for (int i = 0; i < n; i++){
		cin >> arr[i][0]; arr[i][1] = i;
	}

	sort(arr.begin(), arr.end(), [] (ii a, ii b){return a[0] < b[0];});

	for (int i = 0; i < n - 1; i++){
		auto pos = lower_bound(arr.begin() + i + 1, arr.end(), s - arr[i][0],[] (ii a, int v){return v > a[0];});
		int j = (pos - arr.begin());
		// cout << i << " " << j << " " << arr[i][0] << " " << arr[j][0] << endl;
		if (j != n && i != j && arr[i][0] + arr[j][0] == s){
			cout << arr[i][1] + 1 << " " << arr[j][1] + 1;
			return 0;
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}