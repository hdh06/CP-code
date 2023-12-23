#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> p;
vector<string> ans;

void dequy(int i, int a, int b){
	if (a < b) return;
	if (a > n / 2 || b > n / 2) return;
	if (i == n + 1){
		string s;
		for (auto x: p) if (x) s = s + ')'; else s = s + '(';
		ans.push_back(s);
		return;
	}
	
	p.push_back(0);
	dequy(i + 1, a + 1, b);
	p.pop_back();

	p.push_back(1);
	dequy(i + 1, a, b + 1);
	p.pop_back();
}

int main(){
	cin >> n;
	dequy(1, 0, 0);
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << "\n";
	return 0;
}