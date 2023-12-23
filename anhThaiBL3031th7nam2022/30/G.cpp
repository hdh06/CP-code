#include <bits/stdc++.h>

using namespace std;

struct node{
	int L, cnt;
};

node dp[10][11][2][2][2];
bool isMem[10][11][2][2][2];

string L, R;

int num(char c){return c - '0';}

void maximize(node& x, node k){
	if (k.L > x.L) x.L = k.L, x.cnt = k.cnt;
	else if (k.L == x.L) x.cnt += k.cnt;
}

node emrua(int n, int last, bool t1, bool t2, bool is){
	if (n == R.size())
		return {0, 1};
	
	if (isMem[n][last + 1][t1][t2][is]) return dp[n][last + 1][t1][t2][is];

	node ans = {0, 0};
	for (int i = max(last + 1, (t2? num(L[n]): 0)); i <= (t1? num(R[n]) : 9); i++){
		if (is && i == 0) continue;
		node p = emrua(n + 1, i, t1 & (i == num(R[n])), t2 & (i == num(L[n])) , 0);
		p.L += 1;
		maximize(ans, p);
	}

	for (int i = (t2? num(L[n]): 0); i <= (t1? num(R[n]) : 9); i++){
		node p = emrua(n + 1, last, t1 & (i == num(R[n])), t2 & (i == num(L[n])), is & (i == 0));
		maximize(ans, p);
	}
	
	isMem[n][last + 1][t1][t2][is] = 1;
	return dp[n][last + 1][t1][t2][is] = ans;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> L >> R;
		while (L.size() < R.size()) L = '0' + L;

		memset(isMem, 0, sizeof isMem);

		node ans = emrua(0, -1, 1, 1, 1);
		cout << ans.L << " " << ans.cnt << "\n";
	}
	return 0;
}