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
    ll n = 40;
    ll tor, mor;
    pii ans = mp(0, 0);
    cin >> tor >> mor;
    ll i = 0;
    while (n > 0) {
        if (n == 1) {
            if (i % tor == 0) {
                if (i % mor != 0) {
                    ans.first++;
                    n--;
                } else {
                    break;
                }
            } else if (i % mor == 0) {
                ans.second++;
                n--;
            }
        }
        else {
            if (i % tor == 0) {
                n--;
                ans.first++;
            }
            if (i % mor == 0) {
                n--;
                ans.second++;
            }
        }
        i++;
    }
    cout << ans.first << " " << ans.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}