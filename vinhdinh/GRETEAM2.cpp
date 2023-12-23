#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int arr[N];

typedef array<int, 3> iii;

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;	
	string s; cin >> s;
	s = ' ' + s;
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	int nxt[N] = {}, prv[N] = {};
	
	for (int i = 1; i <= n; i++)
		nxt[i] = i + 1, prv[i] = i - 1;
	nxt[n] = -1;
	prv[1] = -1;
	
	set<iii> ms;
	
	for (int i = 1; i < n; i++)
		if (s[i] != s[i + 1])
			ms.insert({abs(arr[i] - arr[i + 1]), i, i + 1});
	
	int A = 0, B = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == 'M') A++; else B++;
	int ans = min(A, B);
	
	cout << ans << "\n";
	for (int i = 1; i <= ans; i++){
		iii z = *ms.begin();
		int x = z[1], y = z[2];
		int px = prv[x], ny = nxt[y];
		ms.erase(ms.begin());
		if (px != -1) ms.erase({abs(arr[x] - arr[px]), px, x});
		if (ny != -1) ms.erase({abs(arr[y] - arr[ny]), y, ny});
		cout << x << " " << y << "\n";
		if (px == -1 && ny == -1) continue;
		if (px == -1){
			prv[ny] = -1;
			continue;
		}
		if (ny == -1){
			nxt[px] = -1;
			continue;
		}
		
		if (s[px] != s[ny]) 
			ms.insert({abs(arr[px] - arr[ny]), px, ny});
		nxt[prv[x]] = nxt[y];
		prv[nxt[y]] = prv[x];
	}
	return 0;
}