#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	int const N = 1e6 + 2;
	vector<int> diff(N, 0);

	while(n--){
		int x, y;
		cin >> x >> y;
		diff[x] ++;
		diff[y + 1] --;
	}	

	int maxn = 0;
	for (int i = 1, num = diff[i]; i < N; i++, num += diff[i]){
		maxn = max(maxn, num);
	}

	for (int i = 1, num = diff[i]; i < N; i++, num += diff[i]){
		if (num == maxn) cout << i << " ";
	}

	return 0;
}