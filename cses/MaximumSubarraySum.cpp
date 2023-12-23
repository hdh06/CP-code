#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
ll const INF = 2*1e5*1e9 + 1; 

int main(){
	int n;
 	cin >> n;

 	vector<ll> arr(n + 1, 0);

 	for (int i = 0; i < n; i++) cin >> arr[i];

 	ll maxn = -INF, sum = 0;

 	for (int i = 0; i < n; i++){
 		maxn = max(maxn, arr[i]);
 		sum += arr[i];

 		maxn = max(maxn, sum);
 		if (sum < 0) sum = 0;
 	}	

 	cout << maxn;
 	return 0;
}