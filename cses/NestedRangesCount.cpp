#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const V = 2 * N;

typedef array<int, 3> iii;

int tree[V];
void upd(int k, int val){
	for (int i = k; i < V; i += (i & -i)) tree[i] += val;
}
int get(int k){
	int ans = 0;
	for (int i = k; i > 0; i -= (i & -i)) ans += tree[i];
	return ans;
}

#define all(x) x.begin(), x.end()

void compress(iii arr[], int n){
	vector<int> brr;
	for (int i = 1; i <= n; i++){
		brr.push_back(arr[i][0]);
		brr.push_back(arr[i][1]);
	}
	sort(all(brr));
	brr.erase(unique(all(brr)), brr.end());
	for (int i = 1; i <= n; i++){
		arr[i][0] = lower_bound(all(brr), arr[i][0]) - brr.begin() + 1;
		arr[i][1] = lower_bound(all(brr), arr[i][1]) - brr.begin() + 1;
	}
}

int main(){
	int n; cin >> n;
	iii arr[N];
	for (int i = 1; i <= n; i++){
		cin >> arr[i][0] >> arr[i][1];
		arr[i][2] = i;
	}
	compress(arr, n);
	sort(arr + 1, arr + n + 1, [](iii a, iii b){
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});
	
	int isIn[N] = {};
	int isOut[N] = {};

	for (int i = 1; i <= n; i++)
		upd(arr[i][1], 1);

	for (int i = 1; i <= n; i++){
		upd(arr[i][1], -1);
		isIn[arr[i][2]] = get(arr[i][1]);
	}

	for (int i = 1; i <= n; i++){
		isOut[arr[i][2]] = get(2 * n) - get(arr[i][1] - 1); 
		upd(arr[i][1], 1);
	}

	for (int i = 1; i <= n; i++) cout << isIn[i] << " \n"[i == n];
	for (int i = 1; i <= n; i++) cout << isOut[i] << " \n"[i == n];
	return 0;
}