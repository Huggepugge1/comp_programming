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
typedef vector<bool> vb;
typedef map<ll, ll> mpii;
typedef map<string, string> mpss;
typedef map<ll, string> mpis;
typedef map <string, ll> mpsi;

vb v(100, false);

ll dijkstra(vector<vii> adj, ll source, ll target) {
    vi dist(adj.size(), 100000000000);
    vi prev(adj.size());
    dist[source] = 0;
    queue<ll> q;
    for (ll i = 0; i < adj.size(); i++) q.push(i);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (pii v : adj[u]) {
            if (v.first >= u) {
                ll alt = dist[u] + adj[u][v.first].second;
                if (alt < dist[v.first]) {
                    dist[v.first] = alt;
                    prev[v.first] = u;
                }
            }
        }
    }
    cout << dist[target] << endl;
    return dist[target];
}

ll shortest(vector<vi> adj, ll start, ll goal, vb visited = v) {
    if (start == goal) {
        return 0;
    }
    visited[start] = true;
    ll ans = 1000000000;
    for(ll i = 0; i < adj[start].size(); i++) {
        if (start != i && !visited[i] && adj[start][i] != -1) {
            ans = min(ans, shortest(adj, i, goal, visited) + adj[start][i]);
        }
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, string>> m(n, mp(0, ""));
    for (ll i = 0; i < n; i++) {
        cin >> m[i].first >> m[i].second;
    }
    vector<vii> adj(n);
    for (ll i = 0; i < n; i++) {
        adj.pb({});
        for (ll j = 0; j < n; j++) {
            adj[i].pb(mp(j, 0));
            if (i != j) {
                for (char x : m[i].second) {
                    if (m[j].second.find(x) != string::npos) {
                        adj[i][j] = mp(j, abs(m[i].first - m[j].first));
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        ans += dijkstra(adj, i, i + 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
