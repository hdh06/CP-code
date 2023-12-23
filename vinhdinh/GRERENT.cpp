#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

typedef array<int, 2> ii;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	ii arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i][0];
	for (int i = 1; i <= n; i++){
		cin >> arr[i][1];
		arr[i][1] += arr[i][0];
	}	

	sort(arr + 1, arr + n + 1);

	priority_queue<int> myque;

	for (int i = 1; i <= n; i++){
		if (!myque.empty() && -myque.top() <= arr[i][0]) myque.pop();
		myque.push(-arr[i][1]);		
	}

	cout << myque.size();
	return 0;
}