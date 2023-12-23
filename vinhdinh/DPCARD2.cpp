#include <bits/stdc++.h>

using namespace std;

int const C = 5, N = 25001;

pair<int, int> arr[N * C];
#define st first
#define nd second

int tree[C][N];
void upd(int x, int y, int val){
	for (; x < N; x += x & -x) 
		for (; y < N; y += y & -y)
			tree[x][y] = max(tree[x][y], val);
}
int get(int x, int y){
	int ans = 0;
	for (;x > 0; x -= x & -x)
		for (;y > 0; y -= y & -y)
			ans = max(ans, tree[x][y]);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int c, n; cin >> c >> n;
	
	for (int i = 1; i <= n * c; i++)
		cin >> arr[i].st >> arr[i].nd;
	
	int p[C];
	for (int i = 1; i <= c; i++) p[i] = i;
	
	int ans = 0;
	int dp[N * C] = {};	
	do{
		//clear tree
		memset(tree, 0, sizeof tree);
		
		//dp
		for (int i = 1; i <= n * c; i++){
			int x = max({1, get(p[arr[i].st] - 1, n) + 1, get(p[arr[i].st], arr[i].nd) + 1});
			upd(p[arr[i].st], arr[i].nd, x);
			ans = max(ans, x);
		}
	}while (next_permutation(p + 1, p + c + 1));
	
	cout << n * c - ans;
	return 0;
}