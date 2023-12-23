#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int tree[N][N];
void upd(int i, int j, int k){
	for (int x = i; x < N; x += x & -x)
		for (int y = j; y < N; y += y & -y)
			tree[x][y] += k;
}
int get(int i, int j){
	int ans = 0;
	for (int x = i; x > 0; x -= x & -x)
		for (int y = j; y > 0; y -= y & -y) 
			ans += tree[x][y];
	return ans;
}

int main(){
	int n, q; cin >> n >> q;	
	bool arr[N][N];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			char t; cin >> t;
			upd(i, j, t == '*');
			arr[i][j] = (t == '*');
		}

	while (q--){
		int t; cin >> t;
		if (t == 1){
			int x, y; cin >> x >> y;
			upd(x, y, -arr[x][y]);
			arr[x][y] ^= 1; // 0 -> 1, 1 -> 0
			upd(x, y, arr[x][y]);			
		}else{
			int a, b, c, d; cin >> a >> b >> c >> d;
			cout << get(c, d) - get(a - 1, d) - get(c, b - 1) + get(a - 1, b - 1) << "\n";
		}
	}
	return 0;
}