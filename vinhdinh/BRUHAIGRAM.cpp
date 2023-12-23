#include <bits/stdc++.h>

using namespace std;

int const N = 27;

int fre[N][N] = {};

int num(char c){
	return c - 'A';
}

int main(){
	int n; cin >> n;
	string s;
	cin >> s;

	for (int i = 1; i < n; i++){
		fre[num(s[i - 1])][num(s[i])]++;
	}

	int maxn = 0, max_i, max_j;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (fre[i][j] > maxn){
				maxn = fre[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	cout << (char)(max_i + 'A') << char(max_j + 'A');
	return 0;
}