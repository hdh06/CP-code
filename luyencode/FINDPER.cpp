#include <bits/stdc++.h>

using namespace std;

int main(){	
	int n;
	cin >> n;
	list<int> perm;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		if (i % 2 == 0){
			perm.push_back(temp);
		}
		else{
			perm.push_front(temp);
		}
	}

	if (n % 2 != 0) reverse(perm.begin(), perm.end());

	for (auto i: perm) cout << i << " ";
	return 0;
}