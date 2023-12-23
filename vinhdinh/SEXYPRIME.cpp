#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e4;

int prime[N];

int const Ns = 570000;
bool sang[Ns] = {1, 1};

vector<int> ans;


void init(){	
	// int dem = 0;
	for (ll i = 2; i <= Ns; i++) if (!sang[i]){
		for (ll j = i * i; j <= Ns; j += i) sang[j] = true;
		if (i >= 6 && sang[i - 6] == false){
			// cout << i << " " << i - 6 << endl;
			ans.push_back(i);
		}
	}
	// cout << dem;
}

int main(){
	init();
	
	int t;
	cin >> t;

	while(t --){
		int n;
		cin >> n;
		cout << ans[n - 1] - 6 << " " << ans[n - 1] << endl;
	}
	return 0;
}