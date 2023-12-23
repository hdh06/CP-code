#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, sum = 0, dem = 0;
    cin >> n;
    ll arr[n];

    for(int i = 0;i < n; i++){
        cin >> arr[i];
        sum += arr[i];    
    }

    double tb = (double)sum / n;
    if (tb >= 4.5) {
        cout << 0;
        return 0;
    }

    sort(arr, arr + n);
    for (int i = 0; i < n && tb < 4.5; i++){ if (arr[i] != 5){
           sum += 5 - arr[i];
           dem++;
           tb = round((double) sum / n);   
       }
    }
    cout << dem;
    return 0;
}
    