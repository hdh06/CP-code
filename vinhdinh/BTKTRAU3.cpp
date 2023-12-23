#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, int> As, Bs, Aw, Bw;
vector<int> a, b;

ll S;

void dequy(int i, ll sum, int dem, map<ll, int> &ms, map<ll, int> &mw, vector<int> arr){
	if (sum > S) return;
	if (i == arr.size()){
		if (ms.find(sum) == ms.end()) ms[sum] = INT_MAX;
		ms[sum] = min(ms[sum], dem);
		mw[sum]++;
		return;
	}

	dequy(i + 1, sum, dem, ms, mw, arr);
	dequy(i + 1, sum + arr[i], dem + 1, ms, mw, arr);
}

int main(){
	int n; cin >> n >> S;
	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		if (i & 1) a.push_back(t);
		else b.push_back(t);
	}

	dequy(0, 0, 0, As, Aw, a);
	dequy(0, 0, 0, Bs, Bw, b);

	ll ans = 0;
	int minn = INT_MAX;

	for (auto x: Aw){
		if (Bw.find(S - x.first) != Bw.end()){
			ans += 1LL*x.second*Bw[S - x.first];
			minn = min(minn, As[x.first] + Bs[S - x.first]);
		}
	}

	if (ans == 0) cout << "KHONG CHON DUOC";
	else cout << ans << " " << minn;
	return 0;
}