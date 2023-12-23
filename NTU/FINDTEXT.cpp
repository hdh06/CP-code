#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	vector<int> p(s.size(), 0);

	for (int j = 0, i = 1; i < s.size();){
		if (s[i] == s[j]){
			p[i] = j + 1;
			j++;
			i++;
		}
		else{
			while(s[i] != s[j] && j != 0) j = p[j - 1];
			if (s[i] != s[j]) p[i] = 0, i++;
		}
	}

	int maxn = 0, maxp = 1;
	for (int i = 0; i < s.size(); i++){
		if (p[i] > maxn){
			maxn = p[i];
			maxp = i + 1 - p[i] + 1;
		}
	}

	cout << maxn << " " << maxp;
	return 0;
}