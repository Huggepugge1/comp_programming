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

map<ll, mpii> memo;

ll prob(ll n, ll m, ll curr, ll goal) {
    if (n == 0) {
        if (curr == goal) {
            return 1;
        }
        return 0;
    }
    if (memo.find(curr) != memo.end() && memo[curr].find(n) != memo[curr].end()) {
        return memo[curr][n];
    }
    ll ans = 0;
    for (ll i = 1; i < m + 1; i++) {
        ans += prob(n - 1, m, curr + i, goal);
    }
    memo[curr][n] = ans;
    return ans;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<double> ans(k, 0.0);
    for (ll i = 1; i < n * m + 1; i++) {
        memo.clear();
        double curr = prob(n, m, 0, i) / pow(m, n);
        pair<double, ll> mi = mp(INT64_MAX, 0);
        for (ll j = 0; j < k; j++) {
            if (ans[j] < mi.first) {
                mi.first = ans[j];
                mi.second = j;
            }
        }
        if (mi.first < curr) {
            ans[mi.second] = curr;
        }
    }
    cout << accumulate(ans.begin(), ans.end(), 0.0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}