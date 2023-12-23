#include <bits/stdc++.h>

using namespace std;

int const N = 1001;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string di = "RLDU*#";
int n, m;

bool check(int x, int y){
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

struct coord{
	int x, y;
};

int main(){
	// freopen("inp.inp","r",stdin); freopen("out.out","w",stdout);
	cin >> n >> m;
	char arr[N][N]; char whatdir[N][N];
	coord A, B;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 'A') A.x = i, A.y = j;
			if (arr[i][j] == 'B') B.x = i, B.y = j;
			whatdir[i][j] = 5;
		}
	}

	bool isvisited[N][N] = {};
	whatdir[A.x][A.y] = 4; 
	queue<coord> myque;

	myque.push(A);

	while (!myque.empty()){
		int i = myque.front().x, j = myque.front().y;

		myque.pop();

		if (isvisited[i][j]) continue;
		isvisited[i][j] = true;

		if (i == B.x && j == B.y) break;

		for (int t = 0; t < 4; t++){
			int g = i + dx[t], h = j + dy[t];
			if (check(g, h) && arr[g][h] != '#' && !isvisited[g][h]){
				whatdir[g][h] = t;
				myque.push({g,h});
			}
		}
	}

	if (isvisited[B.x][B.y]){
		cout << "YES" << endl;
		string ans;
		for (int i = B.x, j = B.y; arr[i][j] != 'A';){
			for (int t = 0; t < 4; t++){
				if (whatdir[i][j] == t){
					ans.push_back(di[t]);
					i -= dx[t];
					j -= dy[t]; 
				}
			}
		}

		// for (int i = 1; i <= n; i++){
		// 	for (int j = 1; j <= m; j++){
		// 		cout << di[whatdir[i][j]] << " ";
		// 	}
		// 	cout << endl;
		// }
		reverse(ans.begin(),ans.end());
		cout << ans.length() << endl << ans;
	}
	else cout << "NO";
	
	return 0;
}