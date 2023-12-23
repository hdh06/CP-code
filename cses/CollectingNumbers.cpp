#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n;

	vector<int> p(n + 1);

	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		p[t] = i;
	}

	int dem = 1;

	for (int i = 2; i <= n; i++){
		dem += p[i] < p[i - 1];
	}

	cout << dem;
	return 0;
}
/*
ver1
	set<int> myset;

	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		auto it = myset.find(t - 1);
		if (it == myset.end()) myset.insert(t);
		else{
			myset.erase(*it);
			myset.insert(t);
		}
 	}

	cout << myset.size();
*/