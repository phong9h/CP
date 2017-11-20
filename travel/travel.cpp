#include <bits/stdc++.h>
using namespace std;

#define FOR(i, l, r) for (int i=l; i<=r; ++i)
#define REP(i, r) for (int i=0; i<(int)r; ++i)
#define sz size
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 100002;
const int inf = 1e9;

int n, m, num[maxn], low[maxn], nChild[maxn], t, id[maxn], w[maxn], XX[maxn];
int l[maxn], par[maxn], k, w2[maxn];
bool deleted[maxn];
vector<int> a[maxn], g[maxn], q;
set<ii> bridge;

void visit(int u, int par) {
    num[u] = ++t; low[u] = inf;
    int cnt = 0;
    REP(i, a[u].sz()) {
        int v = a[u][i];
        if (v==par && cnt==0) {++cnt; continue;}
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            visit(v, u);
            low[u] = min(low[u], low[v]);
            if (num[u]<low[v]) bridge.insert(ii(u, v));
        }
    }
}

void visit_2(int u) {
    id[u] = t;
    w[t]++;
    REP(i, a[u].sz()) {
        int v = a[u][i];
        if (!id[v] && !bridge.count(ii(u, v)) && !bridge.count(ii(v, u)))
            visit_2(v);
    }
}

void initGraph() {
    for (set<ii>::iterator it=bridge.begin(); it!=bridge.end(); ++it) {
        int u = id[it->fi], v = id[it->se];
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int center(int u) {
    REP(i, g[u].sz()) {
        int v = g[u][i];
        if (v!=par[u] && !deleted[v] && nChild[v]>nChild[u]/2)
            return center(v);
    }
    return u;
}

void fixRoot(int u, int p) {
    q.push_back(u);
    nChild[u] = 1;
    w2[u] = w[u];
    REP(i, g[u].sz()) {
        int v = g[u][i];
        if (v!=p && !deleted[v]) {
            par[v] = u;
            l[v] = l[u] + 1;
            fixRoot(v, u);
            nChild[u] += nChild[v];
            w2[u] += w2[v];
        }
    }
}

ll solve(int u) {
    u = center(u);
    l[u] = 0;
    q.clear();
    fixRoot(u, 0);
    deleted[u] = true;
    ll res = 0;
    int i = 1, MAX = 0;
    REP(x, q.sz()) {XX[l[q[x]]] = XX[max(0, k-l[q[x]])] = 0; MAX = max(MAX, l[q[x]]);}
    XX[0] = w[u];
    while (i<(int)q.sz()) {
        int j = i + nChild[q[i]] - 1;
        FOR(x, i, j) {
            res += XX[max(0, k-l[q[x]])]*w[q[x]];
        }
        XX[0] += w2[q[i]];
        FOR(x, i, j) {
            XX[l[q[x]]] += w2[q[x]];
        }
        i = j+1;
    }
    //if (MAX>=k) res += 1LL*XX[k]*w[u];
    REP(i, g[u].sz()) {
        int v = g[u][i];
        if (!deleted[v]) res += solve(v);
    }
    return res;
}

int main() {
    freopen("travel.inp", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    visit(1, 0);
    t = 0;
    FOR(i, 1, n) {
        if (!id[i]) {
            ++t;
            visit_2(i);
        }
    }
    initGraph();
    fixRoot(1, 0);
    cout << solve(1);
}
