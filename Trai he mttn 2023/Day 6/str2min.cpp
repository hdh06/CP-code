#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int pre[26][N];

void str2min(const string &s, int l, int r) {
    if (l == r) return;
    
	int c = 0; 
	while (pre[c][r - 1] < l) c++;
	int i = pre[c][r - 1];
	cout << s[i];
    str2min(s, l, i);
    str2min(s, i + 1, r);
}

int main(){
	string s; cin >> s;
	
	memset(pre, -1, sizeof pre);
	for (int i = 0; i < s.size(); i++){
		if (i)
			for (int j = 0; j < 26; j++)
				pre[j][i] = pre[j][i - 1];
		pre[s[i] - 'a'][i] = i;
	}
	str2min(s, 0, s.size());	
	return 0;
}