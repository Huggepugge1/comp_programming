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

ll s(ll n, ll k) {
    if (k == 0) {
        return n;
    }
    ll m = INT64_MAX;
    string str_num = to_string(n);
    ll l = 0, h = str_num.length() - 1;
    if (str_num[1] == '0') {
        l++;
        if (h == 1) {
            return str_num[0] - 48;
        }
    }
    for (ll i = l; i < h; i++) {
        string str_num_copy = str_num;
        str_num_copy = str_num_copy.erase(i, 1);
        if (stol(str_num_copy) > 0)
            m = min(s(stol(str_num_copy), k-1), m);
    }
    return m;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> k;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        k.pb(mp(a, b));
    }
    for (pair<ll, ll> x : k) {
        cout << s(x.first, x.second) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}