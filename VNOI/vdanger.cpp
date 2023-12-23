#include <bits/stdc++.h>

using namespace std;

int const N = 102;
int const M = 10002;

int n, m;
int arr[M];
int dis[N][N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> arr[i];
    arr[0] = 1;
    arr[++m] = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dis[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans += dis[arr[i - 1]][arr[i]];
    cout << ans;
    return 0;
}
