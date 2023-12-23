#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n+1);arr[0] = 0;
    for (int i = 1; i <= n; i++) cin >>arr[i];
    sort(arr.begin()+1,arr.end(),greater<int>());
    for (int i = 1; i <= n; i++) arr[i] += arr[i-1];
    long long minn = arr[n];
    for (int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        minn = min(minn,arr[temp-1] + arr[n] - arr[temp]);
    }
    cout << minn;
    return 0;
}
    