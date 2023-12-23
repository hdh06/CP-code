#include <bits/stdc++.h>

using namespace std;

char t[] = {'A', 'C', 'G', 'T'};

int main(){
	int n; cin >> n;
	string s; cin >> s;

	int cnt[26] = {};

	int maxn = 0;

	for (int i = 0; i < n; i++){
		if (s[i] != '?'){
		 	cnt[s[i] - 'A']++;
		 	maxn = max(maxn, cnt[s[i] - 'A']);
		 }
	}

	for (int i = 0; i < n; i++) if (s[i] == '?'){
		bool flag = true;
		for (int x = 0; x < 4; x++){
			if (cnt[t[x] - 'A']){
				cnt[t[x] - 'A']--;
				s[i] = t[x];
				flag = false;
				break;
			}
		}
		if (!flag){
			cout << "NO";
			return 0;
		}
	}
	return 0;
}