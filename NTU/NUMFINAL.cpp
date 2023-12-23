#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > f = {
	{0},
	{1},
	{6, 2, 4, 8},
	{1, 3, 9, 7},
	{6, 4},
	{5},
	{6},
	{1, 7, 9, 3},
	{6, 8, 4, 2},
	{1, 9}
};

int const s[] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};

int main(){
	int a, n; cin >> a >> n;	
	cout << f[a % 10][n % s[a % 10]];
	return 0;
}