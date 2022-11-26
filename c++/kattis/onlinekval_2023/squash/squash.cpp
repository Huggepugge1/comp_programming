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
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<ll, ll> mpii;
typedef map<string, string> mpss;
typedef map<ll, string> mpis;
typedef map <string, ll> mpsi;

vector<vector<map<bool, ll>>> memo;
string g;

ll s(ll pos, ll k, bool b) {
    if (pos == g.length()) {
        return 0;
    }
    if (memo[k][pos][b] != 1000000000000) return memo[k][pos][b];
    ll val = g[pos] == 'V' ? 1 : -1;
    if (k == 0) {
        if (b) {
            memo[k][pos][b] = max(val + s(pos + 1, k, true), (ll) 0);
        }
        else return 0;
    }
    else {
        if (b) memo[k][pos][b] = max(s(pos + 1, k, false), val + s(pos + 1, k, true));
        else memo[k][pos][b] = max(s(pos + 1, k, false), val + s(pos + 1, k - 1, true));
    }
    return memo[k][pos][b];
}

void solve() {
    ll n, k;
    cin >> n >> k;
    cin >> g;
    for (ll i = 0; i < k + 1; i++) {
        memo.pb({});
        for (ll j = 0; j < n; j++) {
            memo[i].pb({});
            memo[i][j][false] = 1000000000000;
            memo[i][j][true] = 1000000000000;
        }
    }
    cout << max((ll) 0, s(0, k, false)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}