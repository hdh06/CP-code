#include <bits/stdc++.h>
 
using namespace std;
 
int m, n;
vector<vector<int>> graph;
vector<bool> danhdau;
list<int> mybucket, listout;
 
int DFS(int v,int dem){
    if(danhdau[v]) return INT_MAX;
    danhdau[v] = true;
    mybucket.push_back(v);
    if(v == m){
        listout = mybucket;
        return dem;
    }
    int minn = INT_MAX;
    for (auto u: graph[v]){
        minn = min(minn,DFS(u, dem+1));
    }
    mybucket.pop_back();
    danhdau[v] = false;
    return minn;
}


 
int main() {
    cin >> m >> n;
    graph.resize(m + 1);
    danhdau.assign(m + 1, 0);
    for (int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << DFS(1,1) << endl;
    while(!listout.empty()){
        cout << listout.front() << " ";
        listout.pop_front();
    }
    return 0;
}