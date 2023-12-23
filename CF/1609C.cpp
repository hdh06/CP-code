#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

bool pc(int x){
	if (x < 2) return false;
	for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return false;
	return true;
}

void solve(){
	int n, e; cin >> n >> e;
	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	bool vis[N] = {};
	int ans = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]){
		int tmp = 0; bool is = 0; int bfp = 0;
		for (int j = i; j <= n; j += e){
			if (arr[j] == 1){
				if (is) ans += bfp;
				tmp++;
			}else if (pc(arr[j])){
				ans += tmp;
				bfp = tmp;
				tmp = 0;
				is = 1;
			}else{
				is = 0;
				tmp = 0;
				bfp = 0;
			}
			vis[j] = 1;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}