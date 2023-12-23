#include <bits/stdc++.h>

using namespace std;

int const C = 5, N = 101;

pair<int, int> arr[N * C];
#define st first
#define nd second

int main(){
	int c, n; cin >> c >> n;
	
	for (int i = 1; i <= n * c; i++)
		cin >> arr[i].st >> arr[i].nd;
	
	int p[C];
	for (int i = 1; i <= c; i++) p[i] = i;
	
	int ans = 0;
	int dp[N * C] = {};	
	do{
		for (int i = 1; i <= n * c; i++){
			dp[i] = 1;
			for (int j = i - 1; j >= 1; j--) 
				if ((p[arr[j].st] < p[arr[i].st]) || (p[arr[j].st] == p[arr[i].st] && arr[j].nd < arr[i].nd))
					dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
	}while (next_permutation(p + 1, p + c + 1));
	
	cout << n * c - ans;
	return 0;
}