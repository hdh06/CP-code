#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b; cin >> a >> b;	

	vector<array<int, 2> > ans;
	bool is[26][26] = {};

	for (int i = 0; i < a.size(); i++){
		if (a[i] == b[i]) is[a[i] - 'a'][b[i] - 'a'] = 1;
 	}

	for (int i = 0; i < a.size(); i++){
		int x = a[i] - 'a', y = b[i] - 'a';
		if (x > y) swap(x, y);
		if (x != y){	
			if (is[x][y] == 0){
				for (int j = 0; j < 26; j++) if (is[x][j] == 1 || is[j][y] == 1){
					cout << -1;
					return 0;
				}
				is[x][y] = 1;
				ans.push_back({x, y});
			}
		}
	}

	cout << ans.size() << endl;
	for (auto x: ans) cout << (char)(x[0] + 'a') << " " << (char)(x[1] + 'a') << "\n";

	return 0;
}