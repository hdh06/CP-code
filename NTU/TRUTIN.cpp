#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> iii; //tam i

int const N = 1001;

int n, k; 
string arr[N];

vector<iii> g[N];

bool take[N] = {};

void xuly(int i, int j){
	string a = arr[i], b = arr[j];

	g[i].push_back({j, k, 0});
	g[j].push_back({i, k, 0});

	int dem = 0;

	for (int x = 0; x < k; x++){
		dem += (a[x] != b[x]);
	}

	g[i].push_back({j, dem*2, 1});
	g[j].push_back({i, dem*2, 1});
}

void dequy(int i){

}

int main(){
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) xuly(i, j);
	
	return 0;
}