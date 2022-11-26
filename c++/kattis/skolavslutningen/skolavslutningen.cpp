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
    ll n, m, k;
    cin >> n >> m >> k;
    vs cols;
    map<char, string> c;
    for (int i = 0; i < n; i++) {
        string curr;
        cin >> curr;
        cols.pb(curr);
    }
    for (int i = 0; i < m; i++) {
        string r = "";
        for (int j = 0; j < n; j++) {
            if (r.find(cols[j][i]) == string::npos) {
                r += cols[j][i];
            }
        }
        for (int j = 1; j < r.size(); j++) {
            if (r[j] != r[0]) {
                for (int k = 0; k < cols.size(); k++) {
                    string curr = "";
                    for (int l = 0; l < cols[k].size(); l++) {
                        if (cols[k][l] == r[j]) {
                            curr += r[0];
                        } else {
                            curr += cols[k][l];
                        }
                    }
                    cols[k] = curr;
                }
            }
        }
    }
    ll ans = 0;
    string done = "";
    for (string x : cols) {
        for (char y : x) {
            if (done.find(y) == string::npos) {
                ans += 1;
                done += y;
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