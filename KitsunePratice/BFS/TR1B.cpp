		#include <bits/stdc++.h>

		using namespace std;

		int const N = 1e3 + 1;
		int const T = 4;
		int const dx[] = {0, 0, -1, 1};
		int const dy[] = {1, -1, 0, 0};


		typedef array<int, 2> ii;

		bool check(ii x, int n, int m){
			int a = x[0], b = x[1];
			return (1 <= a && a <= n && 1 <= b && b <= m);
		}

		int main(){
			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
			freopen("EXITROAD.inp", "r", stdin);
			freopen("EXITROAD.out", "w", stdout);
			int n, m; cin >> n >> m;
			int q; cin >> q;

			char arr[N][N];
			int dis[N][N];

			memset(dis, -1, sizeof dis);

			queue<ii> que;

			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++){
					cin >> arr[i][j];
					if (arr[i][j] == 'x'){
						que.push({i, j});
						dis[i][j] = 0;
					}
				} 	

			while (!que.empty()){
				ii x = que.front(); que.pop();
				for (int t = 0; t < T; t++){
					ii y = {x[0] + dx[t], x[1] + dy[t]};	
					if (check(y, n, m) && arr[y[0]][y[1]] != '#' && dis[y[0]][y[1]] == -1){
						dis[y[0]][y[1]] = dis[x[0]][x[1]] + 1;
						que.push(y);
					}
				}	
			}

			while (q--){
				int x, y; cin >> x >> y;
				cout << dis[x][y] << "\n";
			}
			return 0;
		}