#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	
	int dem = 0;

	bool vis[256] = {};

	for (int i = 0; i < s.size(); i++){
		if (!vis[s[i]]) dem++, vis[s[i]] = true;
	}

	if (dem % 2 == 0) cout << "GIRL";
	else cout << "NONO";
	return 0;
}