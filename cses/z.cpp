#include <bits/stdc++.h>

using namespace std;

int const N = 301;
int const T = 4;
int const dx[] = {0, 0, -1, 1};
int const dy[] = {-1, 1, 0, 0};

typedef array<int, 3> iii;

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n, m, k; cin >> n >> m >> k;	
	string s; cin >> s;
	char arr[N][N];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	int dis[N][N][N];
	memset(dis, -1, sizeof dis);

	queue<iii> que;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			dis[i][j][0] = 0;
			que.push({i, j, 0});
		}

	while (!que.empty()){
		int i = que.front()[0];
		int j = que.front()[1];
		int z = que.front()[2];
		que.pop();

		for (int t = 0; t < T; t++){
			int g = i + dx[t], h = j + dy[t];
			if (g < 1 || g > n || h < 1 || h > m) continue;
			int new_z = z + (s[z] == arr[g][h]);
			if (dis[g][h][new_z] == -1){
				dis[g][h][new_z] = dis[i][j][z] + 1;
				que.push({g, h, new_z});
			}
		}
	}

	int ans = INT_MAX;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (dis[i][j][k] != -1)
				ans = min(ans, dis[i][j][k]);

	cout << ans;
	return 0;
}
