#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	priority_queue<long long> myque;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		myque.push(-temp);
	}
	long long tong = 0;
	while (myque.size() != 1){
		long long x = myque.top(); myque.pop();
		long long y = myque.top(); myque.pop();
		myque.push(x+y);
		// cout << x << y << x + y;
		tong += x + y;
	}

	cout << -tong << endl;
	return 0;
}
    