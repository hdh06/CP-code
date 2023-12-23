#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int n, m;
int arr[N][N];
//			0  1   2  3
//         	R  L   U  D
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main(){
	cin >> n >> m;

	if (n == 1 && m == 2){
		cout << "0\n1 1\n1 2\n1 1\n";
		return 0;
	}
	if (n == 2 && m == 1){
		cout << "0\n1 1\n2 1\n1 1\n";
		return 0;
	}

	if (n == 1 || m == 1){
		cout << "1\n" << n << " " << m << " " << 1 << " " << 1 << "\n";
		if (n > 1)
			for (int i = 1; i <= n; i++)
				cout << i << " " << m << "\n";
		else 
			for (int i = 1; i <= m; i++)
				cout << n << " " << i << "\n";
		cout << "1 1\n";
		return 0;
	}

	bool isSwap = (n % 2 != 0 && m % 2 == 0);
	if (isSwap) swap(n, m);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			arr[i][j] = (i & 1? 0: 1);

	for (int i = 1; i <= n - 1; i++){
		if (i & 1)
			arr[i][m] = 3;
		else arr[i][2] = 3;
	}

	for (int i = 2; i <= n; i++)
		arr[i][1] = 2;

	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= m; j++)
	// 		cout << arr[i][j] << " \n"[j == m];

	vector<array<int, 2> > path;
	for (int i = 1, j = 1;;){
		if (isSwap) 
			path.push_back({j, i});
		else path.push_back({i, j});
		if (n % 2 != 0 && m % 2 != 0 && i == n && j == m) j = 1;
		else{
			int t = arr[i][j];
			i += dx[t], j += dy[t];
		}
		if (i == 1 && j == 1) break;
	}
	path.push_back({1, 1});

	if (n % 2 != 0 && m % 2 != 0){
		cout << 1 << "\n";
		cout << n << " " << m << " " << n << " " << 1 << "\n";
	}else cout << 0 << "\n";

	for (auto x: path) cout << x[0] << " " << x[1] << "\n";
	return 0;
}