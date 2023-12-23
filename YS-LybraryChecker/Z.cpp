#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; 
	cin >> s;

	int n = s.size();

	vector<int> z(n, 0);

	cout << n << " ";
	for (int i = 1, x = 0, y = 0; i < n; i++){
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		x = i, y = z[i] + i - 1; 
		cout << z[i] << " ";
	}

	return 0;
}