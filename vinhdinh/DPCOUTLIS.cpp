#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

typedef pair<int, int> ii;
#define st first
#define nd second

void maximize(ii &x, ii a){
	if (x.st < a.st){
		x = a;
	}else if (x.st == a.st) (x.nd += a.nd) %= MOD;
}

ii tree[N];
void upd(int x, ii val){
	for (int i = x; i < N; i += i & -i)
		maximize(tree[i], val);
}
ii get(int x){
	ii ans = {0, 0};
	for (int i = x; i > 0; i -= i & -i)
		maximize(ans, tree[i]);
	return ans;
}

int main(){
	int n; cin >> n;
	
	int arr[N] = {};
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	{
		vector<int> b(arr + 1, arr + n + 1);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		for (int i = 1; i <= n; i++)
			arr[i] = lower_bound(b.begin(), b.end(), arr[i]) - b.begin() + 1;
	}
	
	
	for (int i = 1; i <= n; i++){
		upd(arr[i], {1, 1});
		ii ans = get(arr[i] - 1);
		ans.st += 1;
		upd(arr[i], ans);
	}
	
	cout << get(N - 1).nd;
	return 0;
}