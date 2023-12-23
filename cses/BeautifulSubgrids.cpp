#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
 
int const N = 3e3 + 1;
int const L = 64;
 
ll arr[N][N / L + 2];
 
int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			char c; cin >> c;
			arr[i][j / L] |= (c == '1') * 1LL << (j % L);
		}
	}
	
	ll ans = 0;	
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			ll cnt = 0;
			for (int k = 0; k < N / L + 1; k++)
				cnt += __builtin_popcountll(arr[i][k] & arr[j][k]);
			ans += cnt * (cnt - 1) / 2;
		}
	}
	
	cout << ans;
	return 0;
}
