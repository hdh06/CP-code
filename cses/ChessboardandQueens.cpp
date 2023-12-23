#include <bits/stdc++.h>

using namespace std;

int const N = 9;

int cheo1[N][N] = {
	{0, 0,  0,  0,  0,  0,  0,  0,  0},
	{0, 1, 	2,  3,  4,  5,  6,  7, 	8},
	{0, 2, 	3,  4,  5,  6,  7,  8,  9},
	{0, 3, 	4,  5,  6,  7,  8,  9, 10},
	{0, 4, 	5,  6,  7,  8,  9, 10, 11},
	{0, 5, 	6,  7,  8,  9, 10, 11, 12},
	{0, 6, 	7,  8,  9, 10, 11, 12, 13},
	{0, 7, 	8,  9, 10, 11, 12, 13, 14},
	{0, 8, 	9, 10, 11, 12, 13, 14, 15}
};

int cheo2[N][N] = {
	{0, 0,  0,  0,  0,  0,  0,  0,  0},
	{0, 8,  7,  6,  5,  4,  3,  2,  1},
	{0, 9,  8,  7,  6,  5,  4,  3,  2},
	{0,10, 	9,  8,  7,  6,  5,  4,  3},
	{0,11, 10,  9,  8,  7,  6,  5,  4},
	{0,12, 11, 10,  9,  8,  7,  6,  5},
	{0,13, 12, 11, 10,  9,  8,  7,  6},
	{0,14, 13, 12, 11, 10,  9,  8,  7},
	{0,15, 14, 13, 12, 11, 10,  9,  8}
};

char b[N][N];
bool hang[N], c1[2*N], c2[2*N];

int dequy(int n){
	if (n == 0) return 1;
	int ans = 0;
	for (int i = 1; i < N; i++){
		if (hang[i] || c1[cheo1[n][i]] || c2[cheo2[n][i]]) continue;
		if (b[n][i] == '*') continue;
		hang[i] = true;
		c1[cheo1[n][i]] = true;
		c2[cheo2[n][i]] = true; 
		ans += dequy(n - 1);
		hang[i] = false;
		c1[cheo1[n][i]] = false;
		c2[cheo2[n][i]] = false;
	}
	return ans;
}

int main(){
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++) cin >> b[i][j];
	cout << dequy(8);
	return 0;
}