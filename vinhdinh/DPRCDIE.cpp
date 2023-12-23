#include <bits/stdc++.h>

using namespace std;
//                kk  nc  lua
int const hp[] = {3, -5, -20};
int const ar[] = {2, -10, 5};
int const maxH = 2000;
int const maxA = 2000;

int memo[maxH][maxA][4] = {};
bool ismemo[maxH][maxA][4] = {};

int dequy(int H, int A, int p){
	if (ismemo[H][A][p]) return memo[H][A][p];
	if (H <= 0 || A <= 0) return 0;
	int maxn = 0;
	for (int i = 0; i < 3; i++) if (i != p){
		maxn = max(maxn,dequy(H + hp[i], A + ar[i], i));
	}
	ismemo[H][A][p] = true;
	return memo[H][A][p] = maxn + 1;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int H, A; 
		cin >> H >> A;
		cout << dequy(H, A, 3) - 1 << endl;
	}
	return 0;
}