#include <bits/stdc++.h>

using namespace std;

int a, b;

vector<int> path;

bool dequy(long long n){
	if (n > b) return false;
	if (n == b){
		path.push_back(b);
		return true;
	}

	if (dequy(n*2) || dequy(10* n + 1)){
		path.push_back(n);
		return true;
	}

	return false;
}

int main(){	
	cin >> a >> b;
	if (dequy(a)){
		cout << "YES" << endl;
		cout << path.size() << endl;
		reverse(path.begin(), path.end());

		for (auto x: path) cout << x << " ";
	}
	else cout << "NO";
	return 0;
}