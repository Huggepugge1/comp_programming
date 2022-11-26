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

bool test(vi s, ll m) {
    s[0] += m;
    for (ll i = 1; i < s.size(); i++) {
        s[i] += (s[i - 1] - s[i]) / 2;
        if (s[i] > s[i - 1]) return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vi s;
    for (ll i = 0; i < n; i++) {
        ll curr;
        cin >> curr;
        s.pb(curr);
    }
    if (test(s, 0)) {
        cout << 0 << endl;
        return;
    }
    ll l = 0, h = INT64_MAX;
    while (l + 1 < h) {
        ll m = l + (h - l) / 2;

        if (test(s, m)) h = m;
        else l = m;
    }
    cout << h << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}