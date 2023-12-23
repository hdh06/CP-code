#include <bits/stdc++.h>

using namespace std;

int const N = 1111;

typedef int ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;	

	ll diff[N][N] = {};

	for (int i = 1; i <= n; i++){
		diff[i][1] = 1;
		diff[i][m + 1] = -1;
	}

	for (int t = 1; t <= k; t++){
		int a, b, c, d; ll x;
		cin >> a >> b >> c >> d >> x;
		for (int i = a; i <= c; i++){
			diff[i][b] += x;
			diff[i][d + 1] -= x;
		}
	}

	ll sum = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m + 1; j++){
			sum += diff[i][j];
			if (j <= m) cout << sum << " \n"[j == m]; 
			// cout << diff[i][j] << " \n"[j == m + 1];
 		}
	}
	return 0;
}