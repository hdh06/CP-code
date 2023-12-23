#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	multiset<int> ms;

	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		auto it = ms.upper_bound(t);
		if (it != ms.end()) ms.erase(it);
		ms.insert(t);
	}	

	cout << ms.size();
	return 0;
}