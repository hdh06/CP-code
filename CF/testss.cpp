#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")


//(╯°□°）╯


#define readln(x) getline(cin, (x))
#define file "viec"
#define endl '\n'
#define pb push_back
#define st first
#define nd second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

const ll dx[] = {0, 0, -1, 1, 1, -1, 1, -1};
const ll dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};


void toiuu();
void solve();
int main(){
    freopen(file".INP", "r", stdin);
    freopen(file".OUT", "w", stdout);
    toiuu();
    solve();
    return 0;
}
void toiuu(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve(){
    int n;
    cin >> n;
    
    struct Job {
    int deadline;
    int reward;
    int index;
    };
    
    Job jobs[n];
    for (int i = 0; i < n; i++) {
    cin >> jobs[i].deadline >> jobs[i].reward;
        jobs[i].index = i + 1;
    }
    sort(jobs, jobs + n, [](const Job& a, const Job& b){
        if(a.deadline == b.deadline) 
            return a.reward > b.reward;
        return a.deadline < b.deadline; 
    });
    int time = 0;
    int total_reward = 0;
    vector <int> JobsCantDo;
    for (int i = 0; i < n; i++) {
    if (time + 1 <= jobs[i].deadline) {
        time++;
        total_reward += jobs[i].reward;
        cout << jobs[i].index << endl;
    }
    else{
        JobsCantDo.push_back(jobs[i].index);
    }
    }
    for(auto x : JobsCantDo) cout << x << endl;
    cout << total_reward << endl;
}
//5.2
