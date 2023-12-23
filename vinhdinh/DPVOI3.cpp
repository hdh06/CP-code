#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

struct voi{
	int w, iq, id;
	voi(){}
	voi(int w, int iq, int id) : w(w), iq(iq), id(id) {}
};

voi arr[N];

typedef pair<int, int> ii;
#define st first
#define nd second

int tree[N];
void upd(int x, int val){
	for (;x < N; x += x & -x)
		tree[x] = max(tree[x], val);
}
int get(int x){
	int ans = 0;
	for (;x > 0; x -= x & -x)
		ans = max(ans, tree[x]);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int x, y; cin >> x;
	int n = 0;
	while (x){
		cin >> y;
		n++;
		arr[n] = voi(x, y, n);
		cin >> x;
	}
	
	{//Nen second (IQ)
		vector<int> b;
		for (int i = 1; i <= n; i++) b.push_back(arr[i].iq);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		for (int i = 1; i <= n; i++) arr[i].iq = b.size() - (lower_bound(b.begin(), b.end(), arr[i].iq) - b.begin());
	}
	
	sort(arr + 1, arr + n + 1, [](voi a, voi b){
		if (a.w == b.w) return a.iq > b.iq;
		return a.w < b.w;
	});
	
	for (int i = 1; i <= n; i++)
		upd(arr[i].iq, get(arr[i].iq - 1) + 1);
	
	cout << get(N - 1) << "\n";
	return 0;
}