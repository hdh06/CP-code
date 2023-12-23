#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> p;
bool taken[22];

bool pc(int n){
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;
	return true;	
}

void dequy(int i){
	if (i == n + 1){
		if (pc(p.back() + p.front())){
			for (auto x: p) cout << x << " ";
			cout << endl;
		}
		return;
	}

	for (int x = 2; x <= n; x++) if (!taken[x]){
		if (!pc(x + p.back())) continue;	
		taken[x] = true;
		p.push_back(x);
		dequy(i + 1);
		taken[x] = false;
		p.erase(p.end() - 1);		
	}
}

int main(){
	cin >> n;

	n *= 2;	

	p.push_back(1);
	taken[1] = 1;
	dequy(2);
	return 0;
}