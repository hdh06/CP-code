#include <bits/stdc++.h>

using namespace std;

typedef long double ldb;
typedef pair<ldb, ldb> ii;
#define f first
#define s second

bool comp(ii a, ii b){
	return (ldb)atan2(a.s, a.f) < (ldb)atan2(b.s, b.f);
}

int main(){
	int n; 
	cin >> n;

	vector<ii> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i].f >> arr[i].s;

	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < n; i++) cout << setprecision(0) << fixed << arr[i].f << " " << arr[i].s << endl;
	return 0;
}