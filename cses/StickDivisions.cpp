 #include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int x, n; cin >> x >> n;
	priority_queue<int> que;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		que.push(- x);
	}
	
	ll ans = 0;
	while (que.size() > 1){
		int x = que.top(); que.pop();
		int y = que.top(); que.pop();
		que.push(x + y);
		ans += - x - y;
	}
	
	cout << ans;
	return 0;
}