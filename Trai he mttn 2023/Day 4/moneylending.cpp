#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1010
#endif

using namespace std;

typedef long long ll;

struct node{
	ll a, b, k;
	node(){}
	node(ll a, ll b, ll k) : a(a), b(b), k(k) {}
};


int const N = 5015;

int n;
node arr[N];

ll dp[N][N];

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].a >> arr[i].b >> arr[i].k;
	
	sort(arr + 1, arr + n + 1, [](node A, node B){
		return A.b > B.b;
	});
	
	for (int i = n; i >= 0; i--){
		for (int j = n; j >= 0; j--){
			dp[i][j] = max(dp[i][j], dp[i + 1][j]);
			dp[i][j] = max(dp[i][j], dp[i + 1][j] + arr[i].a - arr[i].b * arr[i].k);
			dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + arr[i].a - arr[i].b * j);
		}
	}
	
	cout << dp[1][0] << "\n";
	return 0;
}