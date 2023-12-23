#include <bits/stdc++.h>

using namespace std;

vector<string> ids = {"0", "1"};

// int cnv(string s){
// 	int ans = 0;
// 	for (int i = 0 ; i < s.size(); i++) if (s[i] == '1')
// 		ans += (1 << i);
// 	return ans;
// }

void init(){
	for (int i = 2; i < 11; i++){
		int sz = ids.size();
		for (int j = sz - 1; j >= 0; j--)
			ids.push_back(ids[j]);
		for (int j = 0; j < ids.size() / 2; j++) ids[j] = ids[j] + '0';
		for (int j = ids.size() / 2; j < ids.size(); j++) ids[j] = ids[j] + '1';
	}
	// for (auto x: ids) cout << cnv(x) << " " << x << "\n";
}

int main(){
	init();

	int t; cin >> t;
	while (t--){
		//ask
		vector<int> que[10];
		for (int i = 0; i < 10; i++){
			for (int j = 1; j <= 1000; j++)
				if (ids[j][i] == '1')
					que[i].push_back(j);
		}

		for (int i = 0; i < 10; i++){
			cout << que[i].size() << " ";
			for (auto x: que[i]) cout << x << " ";
			cout << "\n";
		}

		cout << endl;
		string s; cin >> s;
		for (auto &x: s) if (x == '+') x = '1'; else x = '0';
		bool flag = 0;
		for (int i = 1; i <= 1000; i++){
			if (ids[i] == s){
				flag = 1;
				cout << i << endl;
			}
		}
		if (!flag) cout << 0 << endl;
	}	
	return 0;
}