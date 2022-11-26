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

void solve() {
    ll n, m;
    cin >> n >> m;
    ll k[n][3];
    for (ll i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        k[i][0] = a;
        k[i][1] = b;
        k[i][2] = c;
    }
    ll curr = 0;
    for (ll j = 0; j < n; j++) {
        curr += k[j][0];
    }
    if (curr >= m) {
        cout << 0 << endl;
        return;
    }
    ll l = 0, h = 1000000000000;
    while (l + 1 < h) {
        ll mid = l + (h - l) / 2;
        curr = 0;
        for (ll j = 0; j < n; j++) {
            ll x[3] = {k[j][0], k[j][1], k[j][2]};
            curr += x[0] + x[1] * min(x[2], mid);
        }
        if (curr < m) {
            l = mid;
        } else {
            h = mid;
        }
    }
    cout << h << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}