#include <bits/stdc++.h>
#include <debug.h>

using namespace std;

int const N = 5e5 + 5;

typedef long long ll;

struct toy{
	int c, s;
	toy(){}
	toy(int c, int s): c(c), s(s) {}
};

int n;
toy arr[N];

int preMax[N], preMin[N], sufMax[N], sufMin[N];

#define file "f"

signed main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	freopen(file".inp", "r", stdin);
	freopen(file".ans", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i].c >> arr[i].s;
		
	}
	
	sort(arr + 1, arr + n + 1, [](toy a, toy b){
		if (a.c != b.c) return a.c < b.c;
		return a.s < b.s;
	});

	
	preMax[0] = 0;
	preMin[0] = INT_MAX;
	sufMax[n + 1] = 0;
	sufMin[n + 1] = INT_MAX;
	for (int i = 1; i <= n; i++){
		preMax[i] = max(preMax[i - 1], arr[i].s);
		preMin[i] = min(preMin[i - 1], arr[i].s);
		// debug(arr[i].c, arr[i].s);
	}
	
	for (int i = n; i >= 1; i--){
		sufMax[i] = max(sufMax[i + 1], arr[i].s);
		sufMin[i] = min(sufMin[i + 1], arr[i].s);
	}

	int ans = INT_MAX;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++) if (j - i + 1 < n){
			ans = min(ans, 
				arr[j].c - arr[i].c
				+ max(preMax[i - 1], sufMax[j + 1]) 
				- min(preMin[i - 1], sufMin[j + 1])
				);
			// debug(i, j, ans, preMin[i - 1], sufMin[j + 1]);
		}
	}
	
	cout << ans;
	
	return 0;
}

	
	
// int const L = 20;
// 
// int maxx[2][L][N], minn[2][L][N];
// 
// int getMax(int t, int l, int r){
	// if (l > r) return 0;
	// int k = log2(r - l + 1);
	// return max(maxx[t][k][l], maxx[t][k][r - (1 << k) + 1]);
// }
// int getMin(int t, int l, int r){
	// if (l > r) return INT_MAX;
	// int k = log2(r - l + 1);
	// return min(minn[t][k][l], minn[t][k][r - (1 << k) + 1]);
// }	
	
	// for (int i = 1; i <= n; i++){
		// maxx[0][0][i] = arr[i].c;
		// minn[0][0][i] = arr[i].c;
		// maxx[1][0][i] = arr[i].s;
		// minn[1][0][i] = arr[i].s;
	// }
// 	
	// for (int j = 1; j < L; j++){
		// for (int i = 1; i <= n; i++){
			// maxx[0][j][i] = max(maxx[0][j - 1][i], maxx[0][j - 1][min(n, i + (1 << (j - 1)))]);
			// minn[0][j][i] = min(minn[0][j - 1][i], minn[0][j - 1][min(n, i + (1 << (j - 1)))]);
			// maxx[1][j][i] = max(maxx[1][j - 1][i], maxx[1][j - 1][min(n, i + (1 << (j - 1)))]);
			// minn[1][j][i] = min(minn[1][j - 1][i], minn[1][j - 1][min(n, i + (1 << (j - 1)))]);
		// }
	// }
	
//
