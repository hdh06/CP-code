#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1000
#endif

using namespace std;

int const N = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 + 1;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int id = 0;
map<int, int> dis;

int key(array<int, 9> z){
	int ans = 0;
	for (int i = 0; i < 9; i++)
		ans = ans * 10 + z[i];
	return ans;
}

int p10[10];

int swap(int x, int i, int j){
	int l = (x / p10[8 - i]) % 10;
	int r = (x / p10[8 - j]) % 10;
	x -= l * p10[8 - i];
	x -= r * p10[8 - j];
	x += r * p10[8 - i];
	x += l * p10[8 - j];
	return x;
}

int main(){
	// array<int, 9> p;
	// iota(p.begin(), p.end(), 1);
	// int cnt = 0;
	// do{
		// ++cnt;
		// debug(p, cnt);
		// if (cnt == 10) break;
	// }while (next_permutation(p.begin(), p.end()));
	
	p10[0] = 1;
	for (int i = 1; i < 9; i++) p10[i] = p10[i - 1] * 10;
	
	array<int, 9> z;
	for (int i = 0; i < 9; i++) cin >> z[i];
		
	queue<int> que;
	
	que.push(123456789);
	
	while (!que.empty()){
		int v = que.front(); que.pop();
		
		for (int i = 0; i < 9; i++) for (int d = 1; d < 3; d++){
			int x = i / 3, y = i % 3;
			int g = x + dx[d], h = y + dy[d];
			if (g < 0 || g > 2 || h < 0 || h > 2) continue;
			int nxt = g * 3 + h;
			
			int u = swap(v, i, nxt);
			
			if (dis.find(u) == dis.end()){
				dis[u] = dis[v] + 1;
				que.push(u);
			}
		}
	}
	
	cout << dis[key(z)];
	return 0;
}