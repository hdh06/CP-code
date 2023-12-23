#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end(), greater<int>());
    int i = 0;
    for (; i < n && m > 0; i++)
    {
        m -= arr[i];
    }
    cout << i;
    return 0;
}
 