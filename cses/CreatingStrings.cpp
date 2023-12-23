#include <bits/stdc++.h>

using namespace std;

vector<string> ans;

int fre[26] = {};

string perm;

int n;

void dequy(){
	if (perm.size() == n){
		ans.push_back(perm);
		return;
	}

	for (int i = 0; i < 26; i++) if (fre[i] > 0){
		fre[i]--;
		perm.push_back(i + 'a');
		dequy();
		perm.pop_back();
		fre[i]++;
	}

}

int main(){
	string s; cin >> s;	
	n = s.size();
	for (auto x: s) fre[x - 'a']++;
		
	dequy();

	ofstream fo("out.out");

	cout << ans.size() << "\n";
	for (auto x: ans) fo << x << "\n";
	return 0;
}