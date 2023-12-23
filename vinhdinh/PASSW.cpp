#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("inp.inp", "r", stdin);
	int k;
	cin >> k;
	string s;
	char c;
	while(cin >> c){
		if ('0' <= c && c <= '9') s.push_back(c);
	}

	int st = 0, end = s.size() - k;
	string ans;

	while (ans.size() < k){
		int maxp = -1; char maxn = -1;

		for (int i = st; i <= end; i++){
			if (s[i] > maxn){
				maxn = s[i];
				maxp = i;
			}
		}

		ans.push_back(maxn);

		st = maxp + 1;
		end = min(end + 1, (int)s.size());
	}

	cout << ans;

	bool flag = true;
	for (int i = 0, j = ans.size() - 1; i < j;i++, j--){
		if (ans[i] != ans[j]) flag = false;	
	} 

	cout << (flag?"\nYES":"\nNO");
}