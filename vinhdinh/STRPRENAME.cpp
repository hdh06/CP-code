#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const V = 26;

int psum[V][N] = {};

int main(){
	string s;	
	int n;
	cin >> n >> s;
	s = ' ' + s;

	for (int i = 1; i <= n; i++){
		psum[s[i] - 'a'][i] = 1;
		for (int j = 0; j < 26; j++)
			psum[j][i] += psum[j][i - 1];
	}

	int q; cin >> q;
	while (q--){
		string t;
		cin >> t;
		int fre[V] = {};
		for(auto x: t) fre[x - 'a']++;

		int ans = 0;

		for (int i = 0 ; i < 26; i++){
			int k = lower_bound(psum[i], psum[i] + n + 1, fre[i]) - psum[i];
			ans = max(ans, k);
		}	
		cout << (ans == n + 1?-1:ans) << "\n";
	}
	return 0;
}