#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ii pair<int,ll>
#define pii pair<ii,ll>
#define pb push_back
#define st first
#define nd second

bool bfs(vector<vector<ll> > rflows, int s, int e, int parent[]){
    vector<bool> visited(rflows.size() + 1, 0);
    queue<ll> q;

    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 1;v <= rflows.size();v++){

            if(visited[v] == 0 && rflows[u][v] > 0){
                if(v == e){
                    parent[v] = u;
                    return true;
                }
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;

}
ll ford(vector<vector<ll> > flows, int s, int e){
    vector<vector<ll> > rflows = flows;

    int parent[flows.size() + 1], v, u;
    ll max_flows = 0;

    while(bfs(rflows, s, e, parent)){
        ll path_flow = LLONG_MAX;
        for(v = e;v != s;v = parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rflows[u][v]);
        }

        for(v = e;v != s;v = parent[v]){
            u = parent[v];
            rflows[u][v] -= path_flow;
            rflows[v][u] += path_flow;
        }

        max_flows += path_flow;
    }
    return max_flows;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("Download_Speed_test_6.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<ll> > flows(n + 1, vector<ll>(n + 1));
    for(int i = 0;i < m;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        flows[a][b] = c;
    }
    cout << ford(flows, 1, n);

    return 0;
}