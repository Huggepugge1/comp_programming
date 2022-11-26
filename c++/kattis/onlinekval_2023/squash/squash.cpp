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

vvi memo;

ll s(string g, ll pos, ll k, bool b = false) {
    if (pos == g.length()) {
        return 0;
    }
    ll m = 0;
    if (k == 0) {
        if (b) {
            m = max(s(g, pos + 1, k), s(g, pos + 1, k, true)) + g[pos] == 'V' ? 1 : -1;
        } else {
            return 0;
        }
    }
    else {
        if (b) {
            m = max(s(g, pos + 1, k), max(s(g, pos + 1, k, true) + g[pos] == 'V' ? 1 : -1, s(g, pos + 1, k - 1, true) + g[pos] == 'V' ? 1 : -1));
        } else {
            m = max(s(g, pos + 1, k), s(g, pos + 1, k - 1, true) + g[pos] == 'V' ? 1 : -1);
        }
    }
    memo[k][pos] = m;
    return m;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    string g;
    cin >> g;
    ll m = 0;
    for (ll i = 0; i < k + 1; i++) {
        memo.pb({});
        for (ll j = 0; j < n + 1; j++) {
            memo[i].pb(-1);
        }
    }
    for (ll i = 1; i < k + 1; i++) {
        m = max(m, s(g, 0, i));
    }
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}