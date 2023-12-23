#include <bits/stdc++.h>

using namespace std;

bool col[9], dag1[16], dag2[16];

//j - i + 8
//n - j + 1 - i + 8

int x, y; 

int cdag1(int i, int j){
	return j - i + 8;
}
int cdag2(int i, int j){
	return 8 - j + 1 - i + 8;
}

vector<array<int, 2> > ans;

bool flag = false;

void dequy(int i){
	if (flag) return;
	if (i == 9){
		for (auto x: ans) cout << x[0] << " " << x[1] << "\n";
		flag = true;
		return;
	}

	if (i == x) dequy(i + 1);
	else{
		for (int j = 1; j <= 8; j++) if (!col[j] && !dag1[cdag1(i, j)] && !dag2[cdag2(i, j)]){
			col[j] = dag1[cdag1(i, j)] = dag2[cdag2(i, j)] = 1;
			ans.push_back({i, j});
			dequy(i + 1);
			ans.pop_back();
			col[j] = dag1[cdag1(i, j)] = dag2[cdag2(i, j)] = 0;
		}
	}
}

int main(){
	cin >> x >> y;
	col[y] = dag1[cdag1(x, y)] = dag2[cdag2(x, y)] = 1;

	dequy(1);
	return 0;
}