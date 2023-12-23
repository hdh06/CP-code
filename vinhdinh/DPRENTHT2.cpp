#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

ii const INF = {INT_MAX, INT_MAX};

int main(){
	int n;
	cin >> n;

	vector<ii> arr(n + 1); vector<ii> f(n + 1, {INT_MAX, INT_MAX});

	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

	sort(arr.begin() + 1, arr.end());

	f[0] = {INT_MIN, INT_MIN};

	// for (int i = 1; i <= n; i ++) cout << "{" << arr[i][0] << "," << arr[i][1] << "} "; cout << endl;


	int maxn = 0;
	for (int i = 1; i <= n; i++){
		int k = lower_bound(f.begin(), f.end(), arr[i], [](ii a, ii b){return a[1] < b[0];}) - f.begin();
		// cout << k << endl;
		if (f[k] == INF || f[k][1] > arr[i][1]) f[k] = arr[i];
		maxn = max(maxn, k);
		// for (int i = 0; i <= maxn; i ++) cout << "{" << f[i][0] << "," << f[i][1] << "} "; cout << endl;

	}

	// for (int i = 0; i <= maxn; i ++) cout << "{" << f[i][0] << "," << f[i][1] << "} ";

	cout << maxn;

	// vector<ii> arr = {{1, 2}, {2, 3}, {3, 3}, {4, 5}, {5, 5}};
	// ii x = {3, 2};
	// cout << lower_bound(arr.begin(), arr.end(), x, []()(ii a, ii b){return a[1] < b[0]})- arr.begin();
	return 0;
}