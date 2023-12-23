#include <bits/stdc++.h>

using namespace std;

int const N = 5e5 + 1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, k; 
	cin >> n >> k;

	int arr[N] = {};	
	int p[N] = {};

	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) cin >> p[i];

	deque<int> myque;

	long long tong = 0;

	for (int i = 1; i <= n; i++){
		while (!myque.empty() && p[myque.back()] > p[i]) myque.pop_back();
		while (!myque.empty() && myque.front() < i - k) myque.pop_front();
		myque.push_back(i);

		tong += 1LL*arr[i]*p[myque.front()];
	}
	cout << tong;
	return 0;
}