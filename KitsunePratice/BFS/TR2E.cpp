#include <bits/stdc++.h>

using namespace std;

int add(int k, int n, int m){return (k * (10 % m) % m + (n % m)) % m;}

int const N = 1e3 + 1;

typedef array<int, 2> ii;

void minimize(string &s, string t){
	if (s == "-1") s = t;
	if (s.size() != t.size()){
		if (t.size() < s.size()) s = t;
		return;
	}	
	for (int i = 0; i < s.size(); i++)
		if (t[i] != s[i]){
			if (t[i] < s[i]) s = t;
			return;
		}
}

void solve(){
	int l, r, m, k; cin >> l >> r >> m >> k;

	int dis[N][N]; ii p[N][N];
	memset(dis, -1, sizeof dis);

	queue<ii> que;
	que.push({0, 0});
	dis[0][0] = 0;

	while (!que.empty()){
		int s = que.front()[0], rmd = que.front()[1];
		que.pop();
		for (int i = 0; i <= 9; i++){
			int new_s = s + i;
			int new_rmd = add(rmd, i, m);
			if (dis[new_s][new_rmd] == -1 && new_s <= r){
				dis[new_s][new_rmd] = dis[s][rmd] + 1;
				p[new_s][new_rmd] = {i, rmd};
				que.push({new_s, new_rmd});
			}
		}
	}

	string res = "-1";

	for (int i = l; i <= r; i++) if (dis[i][k] != -1){
		string ans;
		for (int j = i, rmd = k; j > 0;){
			ii d = p[j][rmd];
			ans = (char)(d[0] + '0') + ans;
			j -= d[0];
			rmd = d[1];
		}
		minimize(res, ans);
	}
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}