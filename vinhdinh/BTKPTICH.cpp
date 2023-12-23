#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> p;

void dequy(int i){
	if (i > n) return;
	if (i == n){
		cout << n << " = ";
		for (int x = 0; x < p.size(); x++){
			cout << p[x] << "+\n"[x == p.size() - 1];
		}
		return;
	}
	
	for (int s = (p.size() == 0?1:p.back()); s <= n; s++){
		p.push_back(s);
		dequy(i + s);
		p.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	dequy(0);
	return 0;
}