#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	deque<int> win;

	for (int i = 1; i <= k; i++){
		while (!win.empty() && arr[win.back()] > arr[i]) win.pop_back();
		win.push_back(i);
	}

	cout << arr[win.front()] << "\n";

	for (int i = k + 1; i <= n; i++){
		if (win.front() < i - k + 1) win.pop_front();
		while (!win.empty() && arr[win.back()] > arr[i]) win.pop_back();
		win.push_back(i);
		cout << arr[win.front()] << "\n";
	}
	return 0;
}