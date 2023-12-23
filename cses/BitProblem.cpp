#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 20;

int n;
int arr[N];
int dp1[1 << L];
int dp2[1 << L];
int dp3[1 << L][2];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	{// x | y == x -> 0: 0, 1: 0, 1
		int tmp[1 << L];
		memset(tmp, 0, sizeof tmp);
		for (int i = 1; i <= n; i++)
			dp1[arr[i]]++;
		for (int i = 0; i < L; i++){
			swap(dp1, tmp);
			memset(dp1, 0, sizeof dp1);
			for (int mask = 0; mask < (1 << L); mask++){
				dp1[mask] += tmp[mask];
				if (mask & (1 << i)) dp1[mask] += tmp[mask & ~(1 << i)];
			}
		}
	}
	
	{// x & y == x -> 0: 0, 1. 1: 1
		int tmp[1 << L];
		memset(tmp, 0, sizeof tmp);
		for (int i = 1; i <= n; i++)
			dp2[arr[i]]++;
		for (int i = 0; i < L; i++){
			swap(dp2, tmp);
			memset(dp2, 0, sizeof dp2);
			for (int mask = 0; mask < (1 << L); mask++){
				dp2[mask] += tmp[mask];
				if (~mask & (1 << i)) dp2[mask] += tmp[mask | (1 << i)];
			}
		}
	}
	
	{
		// x & y != 0 -> at least one bit of x and y is 1
		// the IS on the dp for checking that
		int tmp[1 << L][2];	
		memset(tmp, 0, sizeof tmp);
		for (int i = 1; i <= n; i++)
			dp3[arr[i]][1]++;
		for (int i = 0; i < L; i++){
			swap(dp3, tmp);
			memset(dp3, 0, sizeof dp3);
			for (int mask = 0; mask < (1 << L); mask++){
				for (int is = 0; is <= 1; is++){
					dp3[mask][is] += tmp[mask][is || (mask & (1 << i))];
					dp3[mask][is] += tmp[mask ^ (1 << i)][is];
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << dp1[arr[i]] << " " << dp2[arr[i]] << " " << dp3[arr[i]][0] << "\n";
 	
	return 0;
}