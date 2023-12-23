#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1212
#endif

using namespace std;

int const N = 5e3 + 5;
int const L = 20;

typedef long long ll;

struct toy{
	int c, s;
	toy(){}
	toy(int c, int s): 	c(c), s(s) {}
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
	freopen(file".out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i].c >> arr[i].s;
		
	}
	
	sort(arr + 1, arr + n + 1, [](toy a, toy b){
		if (a.c != b.c) return a.c < b.c;
		return a.s < b.s;
	});
	
	// for (int i = 1; i <= n; i++){
		// debug(arr[i].c, arr[i].s);
	// }

	
	preMax[0] = 0;
	preMin[0] = INT_MAX;
	sufMax[n + 1] = 0;
	sufMin[n + 1] = INT_MAX;
	for (int i = 1; i <= n; i++){
		preMax[i] = max(preMax[i - 1], arr[i].s);
		preMin[i] = min(preMin[i - 1], arr[i].s);
	}
	
	for (int i = n; i >= 1; i--){
		sufMax[i] = max(sufMax[i + 1], arr[i].s);
		sufMin[i] = min(sufMin[i + 1], arr[i].s);
	}
	
	int c[L][N] = {}, d[L][N] = {}, e[L][N] = {};
	for (int i = 2; i <= n; i++){
		c[0][i] = - arr[i].c - preMin[i - 1];
		d[0][i] = - arr[i].c + preMax[i - 1];
		e[0][i] = - arr[i].c + preMax[i - 1] - preMin[i - 1];
	}
	
	for (int j = 1; j < L; j++)
		for (int i = 1; i <= n; i++){
			c[j][i] = min(c[j - 1][i], c[j - 1][min(n, i + (1 << (j - 1)))]);
			d[j][i] = min(d[j - 1][i], d[j - 1][min(n, i + (1 << (j - 1)))]);
			e[j][i] = min(e[j - 1][i], e[j - 1][min(n, i + (1 << (j - 1)))]);
		}

	int ans = INT_MAX;
	
	for (int i = 1; i <= n - 1; i++)
		ans = min(ans, arr[i].c - arr[1].c + sufMax[i + 1] - sufMin[i + 1]);
	for (int i = n; i >= 2; i--)
		ans = min(ans, arr[n].c - arr[i].c + preMax[i - 1] - preMin[i - 1]);
	
	for (int i = 2; i <= n - 1; i++){
		int pmin = i, pmax = i;
		for (int l = 1, r = i; l <= r;){
			int mid = (l + r) >> 1;
			if (preMin[mid] < sufMin[i + 1]){
				pmin = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		for (int l = 1, r = i; l <= r;){
			int mid = (l + r) >> 1;
			if (preMax[mid] > sufMax[i + 1]){
				pmax = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		
		//TH1: [L, R] MAX MIN
		ans = min(ans, arr[i].c - arr[min(pmin, pmax)].c + sufMax[i + 1] - sufMin[i + 1]);
		
		//TH2: MIN [L, R] MAX hoac 
		
		if (pmin < pmax){
			int k = log2(pmax - pmin);
			ans = min(ans, arr[i].c + sufMax[i + 1] + min(c[k][pmin + 1], c[k][pmax - (1 << k) + 1]));
		}
		
		//TH3 : MAX [L, R] MIN
		if (pmax < pmin){
			int k = log2(pmin - pmax);
			ans = min(ans, arr[i].c - sufMin[i + 1] + min(d[k][pmax + 1], d[k][pmin - (1 << k) + 1]));
		}
		

		//TH4: MAX MIN [L, R]
		int p =	max(pmax, pmin);
		if (p < i){
			int k = log2(i - p);
			ans = min(ans, arr[i].c + min(e[k][p + 1], e[k][i - (1 << k) + 1]));
		}	
		
		// if (i == 3){
			// debug(pmin, pmax);
		// }
		
		// debug(i, pmin, pmax);
// 		
		// debug(i, ans);
		// debug(pmin, pmax);
		// debug(preMax[i - 1], preMin[i - 1]);
		// debug(sufMax[i + 1], sufMin[i + 1]);
		// debug(i, ans);
	}
	
	cout << ans;
	
	return 0;
}
