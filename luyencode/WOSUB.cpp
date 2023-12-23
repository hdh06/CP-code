#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int S, maxS = 0;
	cin >> S;
	int tong = 0;
	queue<int> myque;

	for (int i = 0; i < n; i++){
		tong += arr[i];
		myque.push(arr[i]);
		while (tong > S && myque.size() != 0) tong -= myque.front(), myque.pop();
		if (tong == S) maxS = max(maxS, (int)myque.size());
	}

	cout << (maxS == 0? -1: maxS);
	return 0;
}