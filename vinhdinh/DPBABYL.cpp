#include <bits/stdc++.h>

using namespace std;

int const N = 3*501;

int main(){
	int n; cin >> n;
	while(n != 0){
		vector<array<int, 3> > arr;

		for (int i = 1; i <= n; i++){
			int x, y, z;
			cin >> x >> y >> z;

			arr.push_back({min(x, y), max(x, y), z});
			arr.push_back({min(y, z), max(y, z), x});
			arr.push_back({min(x, z), max(x, z), y});
		}

		sort(arr.begin(), arr.end());

		long long dp[N];
		int p[N];

		n *= 3;


		int maxn = 0;
		for (int i = 0; i < n; i++){
			dp[i] = arr[i][2]; p[i] = i;
			for (int j = i - 1; j >= 0; j--) if (arr[j][0] < arr[i][0] && arr[j][1] < arr[i][1]) {
				if (dp[i] < dp[j] + arr[i][2]){
					dp[i] = dp[j] + arr[i][2];
					p[i] = j;
				}
			}
			if (dp[maxn] < dp[i]) maxn = i;
		}

		cout << *max_element(dp, dp + n) << endl;

		while (p[maxn] != maxn){
			cout << arr[maxn][0] << " " << arr[maxn][1] << " " << arr[maxn][2] << endl;
			maxn = p[maxn];
		}

		cout << arr[maxn][0] << " " << arr[maxn][1] << " " << arr[maxn][2] << endl;
		cin >> n;
	}
	return 0;
}
    