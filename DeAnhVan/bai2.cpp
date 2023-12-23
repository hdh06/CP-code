#include <bits/stdc++.h>

using namespace std;

int const N = 500;
char mecung[N][N];
int power[N][N][4] = {};
pair<int,int> S, T;

int const cx[4] = {0, 0, 1, -1};
int const cy[4] = {1, -1, 0, 0};

void BFS(){
	memset(power, -1, sizeof power);
	queue<pair<int,int> >myque;
	myque.push(S);
	while(!myque.empty()){
		pair<int,int> p = myque.front();
		int i, j;
		tie(i,j) =  myque.front();
		myque.pop();
		for (int t = 0; t < 4; i++){
			if (mecung[i][j] = '#') power[]
			myque.push({i + cx[t], j + cy[t]});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> mecung[i][j];
			if (mecung[i][j] == 'S') S = {i,j};
			if (mecung[i][j] == 'T') T = {i,j};
		}
	}

    // cerr << "\nTime executed: " << (ldb)clock() / (ldb)CLOCKS_PER_SEC << " sec";
	return 0;
}