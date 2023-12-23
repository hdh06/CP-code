#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int m, n;
int mX[N] = {}, mY[N] = {};
int trace[N] = {};

vector<int> g[N];

int timDMo(){
	queue<int> myque;
	for (int i = 1; i <= n; i++) trace[i] = 0;

	for (int i = 1; i <= m; i++) if (!mX[i]) myque.push(i);

	while (!myque.empty()){
		int i = myque.front(); myque.pop();
		for (auto j: g[i]) if (!trace[j]){
			trace[j] = i;
			if (!mY[j]) return j;
			myque.push(mY[j]);
		}
	}	
	return 0;
}

void moRong(int y){
	int x, next;
	while (y != 0){
		x = trace[y];
		next = mX[x];

		mX[x] = y;
		mY[y] = x;

		y = next;
	}	
}

void solve(){
	int ans = -1;
	while(ans != 0){
		ans = timDMo();
		moRong(ans);
	}
}

int main(){
	int k;
	cin >> m >> n >> k;
	while(k --){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}

	solve();

	int dem = 0;
	for (int i = 1; i <= m; i++) dem += (mX[i] != 0);

	cout << dem;

	// for (int i = 1; i <= m; i++) cout << i << " " << mX[i] << endl;
	return 0;
}