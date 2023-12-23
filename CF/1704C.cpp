#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int arr[N];

void solve(){
	int n, m; cin >> n >> m;	
	for (int i = 1; i <= m; i++)
		cin >> arr[i];

	sort(arr + 1, arr + m + 1);
	priority_queue<int> que;
	que.push(n - arr[m] + arr[1] - 1);
	for (int i = 2; i <= m; i++)
		que.push(arr[i] - arr[i - 1] - 1);
	int curr = 0, save = 0;
	while (!que.empty()){
		int t = que.top(); que.pop();
		t -= curr;
		if (t > 1) t--;
		save += max(0, t);
		curr += 4;
	}
	cout << n - save << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}