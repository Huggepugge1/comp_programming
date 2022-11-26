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

ll alpha_max = 29;

ll rec(ll n, ll pos) {
    if (pos == to_string(n).length()) {
        return 1;
    }
    ll ans = 0;
    if (pos + 1 <= to_string(n).length() && stoi(to_string(n).substr(pos, 1)) != 0) {
        ans += rec(n, pos + 1);
    } if (pos + 2 <= to_string(n).length() && stoi(to_string(n).substr(pos, 2)) <= alpha_max && stoi(to_string(n).substr(pos, 2)) != 0) {
        ans += rec(n, pos + 2);
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    cout << rec(n, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}