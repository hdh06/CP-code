#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int d = n - k;

	string s; cin >> s;

	for (int i = 1; i <= n - k + 1; i++){
		bool flag = true;
		for (int x = i, y = i + d - 1; x < y; x++, y--){
			if (s[x] != s[y]) flag = false;
		}

		if (flag){
			for (int j = i; j <= i + d - 1; j++) cout << s[j];
			return 0;
		}
	}

	cout << "No";
	return 0;
}