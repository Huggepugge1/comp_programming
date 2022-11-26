#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626433832795
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <ll> vi;
typedef vector <string> vs;
typedef vector<char> vc;
typedef vector <pii> vii;
typedef vector <vi> vvi;
typedef map <ll, ll> mpii;
typedef map <string, string> mpss;
typedef map <ll, string> mpis;
typedef map <string, ll> mpsi;

vi memo;

ll dp(vi dishes, ll time, ll m) {
    if (memo[time] != -1) {
        return memo[time];
    }
    if (time == m) {
        return 1;
    }
    ll ans = 0;
    for (ll dish : dishes) {
        if (dish + time <= m) {
            memo[time + dish] = dp(dishes, time + dish, m);
            ans += memo[time + dish];
        }
    }
    return ans;
}

void solve() {
    ll m, n;
    vi dishes;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        ll curr;
        cin >> curr;
        dishes.pb(curr);
    }
    for (int i = 0; i < m + 1; i++) { memo.pb(-1); }
    cout << dp(dishes, 0, m) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}