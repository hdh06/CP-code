#include <bits/stdc++.h>

using namespace std;

int const N = 410;

vector<int> graph[N];

void add_edge(int i){
	for (int j = 1; j <= n; j++){
		graph[j*i].push_back((j+1)*i);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	return 0;
}