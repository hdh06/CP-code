#include <bits/stdc++.h>

using namespace std;

string a, b, p; 
vector<int> link;

string maxtuche(string a, string b){
	if (a.size() > b.size()) return a;
	return b;
}

int const N = 101;
string dp[N][N][N];
bool vis[N][N][N] = {};

string emrua(int i, int j, int cur){
	if (i == a.size() || j == b.size()) return string();
	if (vis[i][j][cur + 1]) return dp[i][j][cur + 1];
	string ans;
	if (a[i] == b[j]){
		int new_cur = cur + 1;
		while (new_cur > 0 && a[i] != p[new_cur])
			new_cur = link[new_cur - 1];
		if (p[new_cur] != a[i]) new_cur -= 1;
		if (new_cur != p.size() - 1)
			ans = maxtuche(ans, a[i] + emrua(i + 1, j + 1, new_cur));
	}
	ans = maxtuche(ans, emrua(i + 1, j, cur));
	ans = maxtuche(ans, emrua(i ,j + 1, cur));
	vis[i][j][cur + 1] = 1;
	dp[i][j][cur + 1] = ans;
	return ans;
}

int main(){
	cin >> a >> b >> p;

	link.resize(p.size());
	for (int j = 0, i = 1; i < p.size();){
		if (p[i] == p[j])
			link[i] = j + 1, i++, j++;
		else{
			while (p[i] != p[j] && j > 0)
				j = link[j - 1];
			if (p[i] != p[j])
				link[i] = 0, i++;
		}
	}

	string ans = emrua(0, 0, -1);
	cout << (ans.size()?ans:"0");
	return 0;
}