#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const N = 2e5 + 1;

#define st first
#define nd second
typedef long long ll;

int n;
pair<int, int> arr[N * 2];

ll dis(ll x, ll y){return x * x + y * y;}
long double angle(pair<int, int> a){
	if (a.nd == 0 && a.st == 0) return 1;
	if (a.nd < 0) return 8.0L * atan(1) - acos(1.0L * a.st / sqrtl(dis(a.st, a.nd)));
	return acos(1.0L * a.st / sqrtl(dis(a.st, a.nd)));
}

void maximize(pair<int, int> &a, pair<int, int> b){
	if (dis(a.st, a.nd) < dis(b.st, b.nd)) a = b;
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].st >> arr[i].nd;
	

	sort(arr + 1, arr + n + 1, [](pair<int, int> a, pair<int, int> b){
		return angle(a) < angle(b);
	});

	for (int i = 1; i <= n; i++)
		arr[i + n] = arr[i];

	pair<int, int> ans = {0, 0};
	pair<int, int> tmp = {0, 0};
	for (int l = 1, r = 0; l <= n; l++, r = max(l - 1, r)){
		// debug(angle(arr[l]));
		while (r + 1 <= 2 * n && dis(tmp.st, tmp.nd) <= dis(tmp.st + arr[r + 1].st, tmp.nd + arr[r + 1].nd) && r + 1 - l + 1 <= n){
			tmp.st += arr[r + 1].st;
			tmp.nd += arr[r + 1].nd;
			r++;
		}
		// debug(l, r, tmp);
		maximize(ans, tmp);
		tmp.st -= arr[l].st, tmp.nd -= arr[l].nd;
	}

	cout << dis(ans.st, ans.nd) << "\n";
	return 0;
}