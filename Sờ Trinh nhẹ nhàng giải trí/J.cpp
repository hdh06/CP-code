#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int, bool> y;

int const A = 999292992, B = 2939393933;

int const N = 6e5 + 1;
	
int p[N] = {1};
void init(){
	for (int i = 1; i < N; i++)
		p[i] = 1LL * p[i - 1] * A % B;
}

int val(string &s){
	int ans = 0;	
	for (int i = 0; i < s.size(); i++){
		(ans += (s[i] * p[i]) % B) %= B;
	}
	return ans;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	int n, m; cin >> n >> m;
	while (n--){
		string s; cin >> s;
		
		int v = val(s);

		for (int i = 0; i < s.size(); i++)
			for (int j = 'a'; j <= 'c'; j++) if (s[i] != j)
				y[(v + (1LL * ((j - s[i] + B) % B) * p[i]) % B) % B] = 1;
	}

	while (m--){
		string s; cin >> s;
		cout << (y[val(s)]? "YES\n": "NO\n");
	}
	return 0;
}