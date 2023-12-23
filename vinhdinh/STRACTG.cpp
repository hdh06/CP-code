#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;

	int ans = INT_MAX;

	char const d[4] = {'A', 'C', 'T', 'G'};

	for (int i = 0; i < n - 4 + 1; i++){
		int dem = 0;

		for (int j = i; j <= i + 3; j++){
			dem += min({
				abs(s[j] - d[j - i]),
				'Z' - s[j] + d[j - i] - 'A' + 1,
				s[j] - 'A' + 'Z' - d[j - i] + 1
			});
		}

		ans = min(ans, dem);
	}

	cout << ans;
	return 0;
}