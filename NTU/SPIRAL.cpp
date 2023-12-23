#include <bits/stdc++.h>

using namespace std;

//ofstream fo("LOG.txt");

unsigned int gen(int n, int i, int j){
	int k = min({n - i + 1, n - j + 1, i, j}) - 1;
	int numor = n / 2;
	int tong;
	int part;

	if (n % 2 != 0 && i == n / 2 + 1 && j == n / 2 + 1) return n*n;

	if (n % 2 != 0) {
		tong = (numor*(numor + 1) - (numor - k)*(numor - k + 1))*4;
		k++;
		part = (numor + 1 - k)*2;
		// fo << numor << " " << k << endl;
	}
	else{
		tong = ((numor*numor) - (numor - k)*(numor - k))*4;
		k++;
		part = (numor - k)*2 + 1;
	}

	// fo << tong << " " << part << endl;

	if (i == k && j <= n - k){
		tong += j - k + 1;
	}
	else if (j == n - k + 1 && i <= n - k){
		tong += part*1;
		tong += i - k + 1;
	}
	else if (i == n - k + 1 && j >= k + 1){
		tong += part*2;
		tong += n - k + 1 - j + 1;
	}
	else if (j == k && i >= k + 1){
		tong += part*3;
		tong += n - k + 1 - i + 1;
	}
	return tong;
}
int const N = 1001;
int const dx[4] = {1, -1, 0, 0};
int const dy[4] = {0, 0, -1, 1};

int n, vs, vt; 
int x, y, r, p;
int dis[N][N];
bool isvisited[N][N];

bool check(int i, int j){
	return (1 <= i && i <= n) && (1 <= j && j <= n);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;		
	while (t--){
		cin >> n >> vs >> vt;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int temp = gen(n, i , j);
				if (temp == vs) x = i, y = j;
				if (temp == vt) r = i, p = j;
				dis[i][j] = INT_MAX;
				isvisited[i][j] = false;
			}
		}

		// cerr << "\nTime of gen executed: " << (long double)clock() / (long double)CLOCKS_PER_SEC << " sec";

		queue<pair<int, int> > q;
		dis[x][y] = 0;
		q.push({x,y});

		 while(!q.empty()) {
        pair<int, int> u = q.front();
        int i = u.first, j = u.second;
        q.pop();
        for(int x = 0; x < 4; x++) {
            int newx = u.first + dx[x], newy = u.second + dy[x];
            if(newx < 1 || newx > n || newy < 1 || newy > n) continue;
            else if(isvisited[newx][newy] == true) continue;
            else if(__gcd(gen(n, i, j), gen(n, newx, newy)) == 1) {
                dis[newx][newy] = dis[u.first][u.second] + 1;
                isvisited[newx][newy] = true;
                q.push({newx, newy});
            } 
        }
    }

		cout << (isvisited[r][p] == false?-1:dis[r][p]) << '\n';
		// cerr << "\nTime BFS executed: " << (long double)clock() / (long double)CLOCKS_PER_SEC << " sec";
		
	}

	return 0;
}


/*                                                                                
10
991 943452 434519
992 267289 430953
1000 548563 114926
993 262143 335373
994 936107 183494
995 340367 430971
996 440191 69363
997 430965 231740
998 901536 966453
999 209400 251279
*/
