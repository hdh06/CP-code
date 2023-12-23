#include <bits/stdc++.h>

using namespace std;

int const N = 2001;

int n, m;
int arr[N][N] = {};

typedef long long ll;

int is(int i, int j){
    return (arr[i][j] == arr[(i + 1) % n][j] && arr[i][j] == arr[i][(j + 1) % m] && arr[i][j] == arr[(i + 1) % n][(j + 1) % m]);
}

int main(){
    ios_base::sync_with_stdio(0); // the
    cin.tie(nullptr);              // magical
    cout.tie(nullptr);              // lines
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
            ans += is(i, j);

    int Vsum[N] = {}, Hsum[N] = {};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            Vsum[i] += is(i, j);
        
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n - 1; i++)
            Hsum[j] += is(i, j);
    

    int t; cin >> t;
    while (t--){
        int type, x; cin >> type >> x;
        int del = 0;
        if (type == 1 || type == 3){
            x %= n;
            if (type == 3) x = (n - x) % n;
            if (x != 0)
                del += Vsum[n - 1] - Vsum[n - x - 1];
        }
        if (type == 2 || type == 4){
            x %= m;
            if (type == 4) x = (m - x) % m;
            if (x != 0)
                del += Hsum[m - 1] - Hsum[m - x - 1];
        }
        cout << ans + del << "\n";
    }
    return 0;
}