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
    int n, m, ans = 0;
    cin >> n >> m;
    vvi area;
    vi empty(m+2, 0);
    area.pb(empty);
    for (int i = 0; i < n; i++) {
        area.pb({});
        area[i+1].pb(0);
        for (int j = 0; j < m; j++) {
            int curr;
            cin >> curr;
            area[i+1].pb(curr);
        }
        area[i+1].pb(0);
    }
    area.pb(empty);

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (area[i][j] != 0) {
                ans += area[i][j] * 4 - min(area[i][j - 1], area[i][j]) - min(area[i][j + 1], area[i][j]) -
                       min(area[i - 1][j], area[i][j]) - min(area[i + 1][j], area[i][j]) + 2;
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