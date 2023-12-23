#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    bool mymap[2000001];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mymap[arr[n - 1]] = true;
    arr[n-1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (mymap[arr[i]] != true)
        {
            mymap[arr[i]] = true;
            arr[i] = arr[i+1] + 1;
        }
        else arr[i] = arr[i+1];
    }
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;
        cout << arr[u - 1] << endl;
    }
    return 0;
}
    