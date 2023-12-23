#include <bits/stdc++.h>

using namespace std;

map<int, bool> m;

int const A = 1002381903, B = 1203819238;

int const N = 3e5 + 1;
	
int p[N] = {1};
void init(){
	for (int i = 1; i < N; i++)
		p[i] = 1LL * p[i - 1] * A % B;
}

int val(string s){
	int ans = 0;
	for (int i = s.size() - 1; i >= 0; i--){
		ans = 1LL * ans * A % B;
		(ans += s[i]) %= B;
	}
	return ans;
}

int main(){
	init();
	int n, int m; cin >> n >> m;
	while (n--){
		string s; cin >> s;
		int v = val(s);

		for (int i = 0; i < s.size(); i++)
			for (int j = 'a'; j <= 'c'; j++) if (s[i] != j)
				m[v + (1LL * (j - s[i]) * p[i]) % B] = 1;
	}

	while (m--){
		string s; cin >> s;
		cout << (m[val(s)]? "YES\n": "NO\n");
	}
	return 0;
}