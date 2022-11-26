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
    ll n;
    cin >> n;
    vi q;
    for (ll i = 0; i < n; i++) {
        ll curr;
        cin >> curr;
        if (curr != 0) {
            q.pb(curr);
        }
    }
    ll ans = q[0] * 2, curr;
    for (ll i = 1; i < q.size(); i++) {
        ans += q[i] * (i + 2);
    }
    curr = ans;
    for (ll i = 1; i < q.size() + 1; i++) {
        curr -= q[i - 1] * (i + 1) - q[i - 1] * (i);
        ans = max(ans, curr);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}