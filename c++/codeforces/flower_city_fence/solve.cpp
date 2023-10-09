
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
typedef map<string, ll> mpsi;

void solve() {
    ll t;
    cin >> t;
    ll n;
loop:
    while (cin >> n) {
        vi a;
        for (int i = 0; i < n; i++) {
            ll curr;
            cin >> curr;
            a.pb(curr);
        }
        for (int i = 1; i <= a[0]; i++) {
            ll low = 0, high = a.size();
            while (low < high - 1) {
                ll mid = low + ((high - low) / 2);
                if (a[mid] >= i) low = mid;
                else high = mid;
            }
            if (a[i - 1] != (low + 1)) {
                print("NO");
                goto loop;
            }
        }
        print("YES");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
