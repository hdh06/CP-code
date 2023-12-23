#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int kq = 0;

	for (int i = 0; i < n; i++){
		int win = INT_MAX;
		for (int j = 0; j < m; j++){
			int temp;
			cin >> temp;
			win = min(win, temp);
		}
		kq = max(kq, win);
	}

	cout << kq;
	return 0;
}