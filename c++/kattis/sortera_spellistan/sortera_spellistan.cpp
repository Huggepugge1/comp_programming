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

void solve() {
    ll n;
    cin >> n;
    vi l;
    for (ll i = 0; i < n; i++) {
        ll curr;
        cin >> curr;
        l.pb(curr);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i+1; j < n; j++) {
            if (l[i] > l[j]) {
                l[i], l[j] = l[j], l[i];
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}