#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;

typedef pair<int, int> ii;
#define st first
#define nd second

int tree[N];
void upd(int k, int val){
	for (int i = k; i < N; i += i & -i)
		tree[i] = max(tree[i], val);
}
int get(int k){
	int ans = 0;
	for (int i = k; i > 0; i -= i & -i)	
		ans = max(ans, tree[i]);
	return ans;
}

vector<int> g[N];

int main(){
	int n; cin >> n;
	
	ii arr[N]; 	
	for (int i = 1; i <= n; i++){
		cin >> arr[i].st >> arr[i].nd;
	}
	
	{
		vector<int> b;
		for (int i = 1; i <= n; i++) b.push_back(arr[i].st), b.push_back(arr[i].nd);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		for (int i = 1; i <= n; i++){
			arr[i].st = lower_bound(b.begin(), b.end(), arr[i].st) - b.begin() + 1;
			arr[i].nd = lower_bound(b.begin(), b.end(), arr[i].nd) - b.begin() + 1;
		}
	}
	
	// for (int i = 1; i <= n; i++)
		// g[arr[i].st].push_back(arr[i].nd);
	
	// for (int i = 1; i < N; i++){
		// // vector<int> tmp;
		// // for (auto x: g[i])
			// // tmp.push_back(get(x - 1) + 1);
// // 		
		// // int id = 0;
		// // for (auto x: g[i])
			// // upd(x, tmp[id++]);
	// }
	
	sort(arr + 1, arr + n + 1);
	
	for (int i = 1; i <= n; i++)
		upd(arr[i].nd, get(arr[i].nd) + 1);
	
	cout << n - get(N - 1);
	cout << int(n);
	return 0;
}