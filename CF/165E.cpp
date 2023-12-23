#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int const V = 4e6 + 1;
int const L = 22;

int n;
int arr[N];

int dp1[1 << L], dp2[1 << L];

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n;
	
	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);z
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		dp1[arr[i]] = arr[i];
	}			
			
	for (int i = 0; i < L; i++){
		for (int mask = 0; mask < (1 << L); mask++){
			
			if (dp2[mask] == -1)
				dp2[mask] = dp1[mask ^ (1 << i)];
			if ((~mask & (1 << i)) && dp2[mask] == -1)
				dp2[mask] = dp1[mask];
		}
		swap(dp1, dp2);	
		memset(dp2, -1, sizeof dp2);
	}

	for (int i = 1; i <= n; i++){
		cout << dp1[arr[i]] << " ";
	}
	return 0;
}