#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> ans(n + 1), arr(n + 1);
	stack<int> mystack;

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		int pos = 0;
		while (!mystack.empty() && arr[mystack.top()] >= arr[i]) mystack.pop();
		if (!mystack.empty()) pos = mystack.top();
		ans[i] = pos;
		mystack.push(i);
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}
//Input:
/*
8
2 5 1 4 8 3 2 5
*/