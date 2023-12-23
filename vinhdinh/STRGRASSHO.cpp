#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;

	string s; cin >> s;

	int G_pos = 0, T_pos = 0;

	for (int i = 0; i < n; i++){
		if (s[i] == 'G') G_pos = i;
		if (s[i] == 'T') T_pos = i;
	}	

	if (G_pos > T_pos) swap(G_pos, T_pos);

	for (int i = G_pos; i <= T_pos; i += k){
		if (i == T_pos){
			cout << "YES";
			return 0;
		}
		if (s[i] == '#') break;
	}	

	cout << "NO";
	return 0;
}