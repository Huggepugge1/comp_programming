#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<ll, ll> mpii;
typedef map<string, string> mpss;
typedef map<ll, string> mpis;
typedef map <string, ll> mpsi;

vvi memo;

ll shoppingSpree(vi paintings, ll k, ll m) {
    if (k == 0) {
        return paintings[m];
    }
    if (memo[m][k] != -1) {
        return memo[m][k];
    }
    ll ans = 1000000000000000;
    for (ll i = m + 1; i < paintings.size() - k + 1; i++) {
        ans = min(ans, shoppingSpree(paintings, k - 1, i) + i - m);
    }
    memo[m][k] = ans + paintings[m];
    return memo[m][k];
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vi paintings;
    for (int i = 0; i < n; i++) {
        ll curr;
        cin >> curr;
        paintings.pb(curr);
    }
    for (ll i = 0; i < n; i++) {
        memo.pb({});
        for (ll j = 0; j < k; j++) {
            memo[i].pb(-1);
        }
    }
    ll ans = INT64_MAX;

    for (ll i = 0; i < paintings.size() - k + 1; i++) {
        ans = min(shoppingSpree(paintings, k - 1, i), ans);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}