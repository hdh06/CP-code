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

void maximize(ii &x, ii val){
	if (x.st < val.st) x = val;
}

ii tree[N];
void upd(int x, ii val){
	for (;x < N; x += x & -x)
		maximize(tree[x], val);
}
ii get(int x){
	ii ans = {0, 0};
	for (;x > 0; x -= x & -x)
		maximize(ans, tree[x]);
	return ans;
}

int main(){
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
		if (a.w == b.w) return a.iq < b.iq;
		return a.w < b.w;
	});
	
	int p[N] = {};
	
	for (int i = 1; i <= n; i++){
		ii ans = get(arr[i].iq);
		upd(arr[i].iq, {ans.st + 1, arr[i].id});
		p[arr[i].id] = ans.nd;
	}
	
	ii ans = get(N - 1);
	cout << ans.st << "\n";
	vector<int> z;
	while (ans.nd){
		z.push_back(ans.nd);
		ans.nd = p[ans.nd];
	}
	reverse(z.begin(), z.end());
	for (auto x: z) cout << x << " ";
	return 0;
}