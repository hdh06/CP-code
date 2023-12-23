#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int const N = 3001;
int const MOD = 1e8;

void xuly(int t){
	int dem = 0;
	int tong = t;
	while (tong > 0) dem++, tong /= 10;

	for (int i = 1; i <= 8 - dem; i++) cout << 0;
	cout << t << endl;
}

int main(){
	int n;
	cin >> n;
	while(n != -1){
		ii arr[N];
		for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

		sort(arr + 1, arr + n + 1);

		int dp[N] = {};

		int tong = 0;
		for (int i = 1; i <= n; i++){
			dp[i] = 1;
			for (int j = i - 1; j >= 1; j--) if (arr[j][1] <= arr[i][0]){
				dp[i] += dp[j]; 
				dp[i] %= MOD;
			}
			tong += dp[i];
			tong %= MOD;
		}
		
		xuly(tong);
		cin >> n;
	}	
	return 0;
}