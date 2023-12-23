#include <bits/stdc++.h>

using namespace std;

int const N = 21;

char arr[N][N];

int main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> arr[i][j];
				
		string s = "vika";
		int pos = 0;
		for (int j = 1; j <= m; j++) 
			for (int i = 1; i <= n; i++){
				if (pos == 5) break;
				if (arr[i][j] == s[pos]){
					pos++;
					break;
				}
			}
		
		if (pos == 4)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}	
	return 0;
}