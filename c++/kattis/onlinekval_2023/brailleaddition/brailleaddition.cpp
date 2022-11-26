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
    mpsi btoi = {
            {"*.....", 1},
            {"*.*...", 2},
            {"**....", 3},
            {"**.*..", 4},
            {"*..*..", 5},
            {"***...", 6},
            {"****..", 7},
            {"*.**..", 8},
            {".**...", 9},
            {".***..", 0}
    };

    mpis itob = {
            {1, "*....."},
            {2, "*.*..."},
            {3, "**...."},
            {4, "**.*.."},
            {5, "*..*.."},
            {6, "***..."},
            {7, "****.."},
            {8, "*.**.."},
            {9, ".**..."},
            {0, ".***.."}
    };
    ll n;
    cin >> n;
    vs N;
    for (ll i = 0; i < 1000; i++) {
        N.pb("");
    }
    for (ll i = 0; i < n * 3; i++) {
        string curr;
        cin >> curr;
        N[i % n] += curr;
    }
    ll m;
    cin >> m;
    vs M;
    for (ll i = 0; i < 1000; i++) {
        M.pb("");
    }
    for (ll i = 0; i < m * 3; i++) {
        string curr;
        cin >> curr;
        M[i % m] += curr;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += btoi[N[i]] * pow(10, n - i - 1);
    }
    for (ll i = 0; i < m; i++) {
        ans += btoi[M[i]] * pow(10, m - i - 1);
    }

    vs strans(10000, "");
    n = to_string(ans).length();
    while (true) {
        strans[to_string(ans).length() - 1] = itob[ans % 10];
        ans /= 10;
        if (ans == 0) {
            break;
        }
    }


    for (ll i = 0; i < n * 3; i++) {
        cout << strans[i % n][i / n * 2] << strans[i % n][i / n * 2 + 1] << " ";
        if ((i + 1) % n == 0) {
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}