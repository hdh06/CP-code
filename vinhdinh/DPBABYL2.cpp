#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;

struct cube{
	int x, y, z;
	cube(){}
	cube(int x, int y, int z) : x(x), y(y), z(z){}
};

int n;
cube arr[N];

ll tree[N];
void upd(int x, ll val){
	for (;x < N; x += x & -x)
		tree[x] = max(tree[x], val);
}
ll get(int x){
	ll ans = 0;
	for (;x > 0; x -= x & -x)
		ans = max(ans, tree[x]);
	return ans;
}

void solve(){
	for (int i = 1; i <= 3 * n; i += 3){
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
		arr[i    ] = cube(min(arr[i].x, arr[i].y), max(arr[i].x, arr[i].y), arr[i].z);
		arr[i + 1] = cube(min(arr[i].y, arr[i].z), max(arr[i].y, arr[i].z), arr[i].x);
		arr[i + 2] = cube(min(arr[i].z, arr[i].x), max(arr[i].z, arr[i].x), arr[i].y); 
	}
	
	{
		vector<int> b;
		for (int i = 1; i <= 3 * n; i++) b.push_back(arr[i].y);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		
		for (int i = 1; i <= 3 * n; i++)
			arr[i].y = lower_bound(b.begin(), b.end(), arr[i].y) - b.begin() + 1;
	}
	
	sort(arr + 1, arr + 3 * n + 1, [](cube a, cube b){
		if (a.x == b.x) return a.y > b.y;
		return a.x < b.x;
	});
	
	memset(tree, 0, sizeof tree);
	
	for (int i = 1; i <= 3 * n; i++)
		upd(arr[i].y, get(arr[i].y - 1) + arr[i].z);
	
	cout << get( N - 1) << "\n";
}
int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n;
	while (n){
		solve();
		cin >> n;
	}
	return 0;
}