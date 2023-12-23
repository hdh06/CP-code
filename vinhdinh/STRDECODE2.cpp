#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	if (s.size() % 2 == 0) s = '#' + s;

	int n = s.size();

	int mid = n / 2;

	string ans;
	ans = ans + s[mid];
	for (int i = mid - 1, j = mid + 1; i >= 0 && j < n; i--, j++){
		ans = ans + s[j];
		ans = ans + s[i];
	}

	if (ans[ans.size() - 1] == '#') ans.erase(ans.size() - 1, 1);

	cout << ans;
	return 0;
}