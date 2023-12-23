#include <bits/stdc++.h>
 
using namespace std;
 
int const N = 2e5 + 1;
 
vector<int> g[N], h[N];
 
int main(){
    int n, m; cin >> n >> m;
    while (m--){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        h[b].push_back(a);
    }
 
    int sign[N] = {};
    memset(sign, -1, sizeof sign);
 
    for (int i = 1; i <= n; i++){
        if (g[i].size() > 0 && h[i].size() > 0){
            for (auto v: g[i]){
                if (sign[v] == 1){
                    cout << -1;
                    return 0;
                }
                sign[v] = 0;
            }
            for (auto v: h[i]){
                if (sign[v] == 0){
                    cout << -1;
                    return 0;
                }
                sign[v] = 1;
            }
        }
    }
 
    for (int i = 1; i <= n; i++) if (sign[i] == -1){
        if (g[i].size() > 0 && h[i].size() == 0){
            bool flag = 0;
            for (auto v: g[i]){
                if (sign[v] == 1){
                    cout << -1;
                    return 0;
                }
                if (sign[v] == 0)
                    flag = 1;
            }
 
            if (flag)
                for (auto v: g[i]){
                    sign[v] = 0;
                }
            else{
                sign[i] = 1;
            }
        }else if (g[i].size() == 0 && h[i].size() > 0){
            bool flag = 0;
            for (auto v: h[i]){
                if (sign[v] == 0){
                    cout << -1;
                    return 0;
                }
                if (sign[v] == 1)
                    flag = 1;
            }
 
            if (flag)
                for (auto v: h[i])
                    sign[v] = 1;
            else sign[i] = 0;
        }
    }
 
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (sign[i] != -1) cnt++;
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++)
        if (sign[i] != -1) cout << i << " " << sign[i] << "\n";
    return 0;
}