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
    string s;
    cin >> n >> s;

    ll a = 0, b = 0;
    pii ans = mp(0, 0);
    for (char x : s) {
        if (x == 'A') {
            a += 1;
        } else {
            b += 1;
        }
        if (ans.first + ans.second < 2) {
            if (a >= 25 && a - b >= 2) {
                a = 0;
                b = 0;
                ans.first += 1;
            } else if (b >= 25 && b - a >= 2) {
                a = 0;
                b = 0;
                ans.second += 1;
            }
        } else {
            if (a >= 15 && a - b >= 2) {
                a = 0;
                b = 0;
                ans.first += 1;
            } else if (b >= 15 && b - a >= 2) {
                a = 0;
                b = 0;
                ans.second += 1;
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}