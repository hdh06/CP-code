#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e7;

bool sang[N] = {1, 1};

ll tong = 0;
int n;

// vector<ll> ans;

void init(){
	for (ll i = 2; i < N; i++) if (!sang[i]){
		for (ll j = i*i; j < N; j += i){
			sang[j] = true;
		}
		
	}

	for (ll i = 2; i < N; i++) if (!sang[i]){
		for (ll j = i*i; j < N; j += i){
			if (sang[j/i] == false && j <= n){
				tong += j;
				// cout << j << " ";
			}
		}
	}

	// for (int i = 0; ans[i] <= n && i < ans.size(); i++){
	// 	for (int j = i; ans[j] <= n && j < ans.size(); j++){
	// 		if (ans[i]*ans[j] <= n) tong += ans[i]*ans[j];
	// 	}
	// }

	// cout << ans[ans.size()-1] << " " << ans[ans.size()-2] << endl;
}

int main(){
	cin >> n;
	init();

	cout << n << " " << tong;
	
	return 0;
}