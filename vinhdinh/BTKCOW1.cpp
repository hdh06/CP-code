#include <bits/stdc++.h>

using namespace std;

int const N = 21;

typedef long long ll;

ll arr[N] = {};

int min_dem = INT_MAX;

ll dequy(int n, ll m){
	if (n == 0){
		if (m == 0ll){
			return 1;
		}
		return 0; 
	}
	return dequy(n - 1, m) + dequy(n - 1, m - arr[n]);
}

int dem(int n, ll m){
	if (m < 0ll) return 1000000;

	if (n == 0){
		if (m == 0ll){
			return 0;
		}
		return 1000000; 
	}

	int ans1 = dem(n - 1, m);
	int ans2 = dem(n - 1, m - arr[n]);

	// if (ans2 != -1) ans2++;

	return min(ans1, ans2 + 1);
}

int main(){
	int n; ll m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout << dequy(n, m) << " " << dem(n, m);
	return 0;
}