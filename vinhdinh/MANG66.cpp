#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; 
	cin >> n >> m;

	vector<int> tong(m, 0);
	while(n--){
		for (int j = 0; j < m; j++){
			int temp; cin >> temp;
			tong[j] += temp;
		}
	}

	for (auto i: tong) cout << i << "\n";
	return 0;
}