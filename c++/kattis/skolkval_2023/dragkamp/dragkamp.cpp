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

bool t(ll a1, ll a2, ll a3, ll a4, ll b1, ll b2, ll b3, ll b4) {
    cout << a1 + a2 * 2 + a3 * 3 + a4 * 4 << " " << b1 + b2 * 2 + b3 * 3 + b4 * 4 << endl;
    if (a1 + a2 * 2 + a3 * 3 + a4 * 4 == b1 + b2 * 2 + b3 * 3 + b4 * 4) {
        return true;
    }
    return false;
}

void solve() {
    ll s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}