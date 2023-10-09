#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define print(x) cout << (x) << endl


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
    int t;
    cin >> t;
    int n, x;
    while (cin >> n >> x) {
        vi a;
        for (int i = 0; i < n; i++) {
            ll curr;
            cin >> curr;
            a.pb(curr);
        }
        ll low = 0, high = INT_MAX;
        while (low < high - 1) {
            ll mid = low + ((high - low) / 2);
            ll w = 0;
            for (ll currA : a) {
                w += max(mid - currA, 0ll);
            }
            if (w <= x) low = mid;
            else high = mid;
        }
        print(low);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}