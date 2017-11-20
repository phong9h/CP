#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <memory.h>
#include <iomanip>
#include <cassert>
#include <set>
#include <map>
using namespace std;

#define maxn 107
#define FOR(i, l, r) for (int i=l; i<=r; ++i)
#define FORD(i, r, l) for (int i=r; i>=l; --i)
#define REP(i, r) for (int i=0; i<(int)r; ++i)
#define REPD(i, r) for (int i=(int)r-1; i>=0; --i)
#define fi first
#define se second
#define mk make_pair
#define nil NULL
#define y0 __y0
#define y1 __y1
#define x0 __x0
#define x1 __x1
#define next asdfa
#define sz size
#define DB(X) {cerr << #X << " = " << X << '\n';}
#define PR(A, n) {cerr << #A << " = "; FOR(i, 1, n) cerr << A[i] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i] << ' '; cerr << '\n';}
typedef long long ll;
typedef double db;
typedef pair<int, int> ii;
typedef vector<int> vi;
const ll inf = 1e18;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, m, k, s, t, c[maxn][maxn], f[maxn][maxn], trace[maxn];
ll d[maxn], res;
vector<ii> a[maxn];
queue<int> qu;
bool inqueue[maxn];
vector<int> path;

bool findpath() {
	FOR(i, 1, n) d[i] = inf;
	d[s] = 0;
	qu.push(s);
	memset(inqueue, false, sizeof(inqueue));
	inqueue[s] = true;
	while (qu.sz()) {
		int u = qu.front(); qu.pop();
		inqueue[u] = false;
		REP(i, a[u].sz()) {
			int v = a[u][i].fi, w = a[u][i].se;
			if (c[u][v]>f[u][v] && d[v]>d[u] + (f[u][v]>=0 ? w : -w)) {
				d[v] = d[u] + (f[u][v]>=0 ? w : -w);
				trace[v] = u;
				if (!inqueue[v]) {
					inqueue[v] = true;
					qu.push(v);
				}
			}
		}
	}
	return d[t]<inf;
}

int incFlow() {
	int v = t;
   	ll delta = inf;
	while (v!=s) {
		int u = trace[v];
		if (f[u][v]<0) delta = min(delta, -1LL*f[u][v]);
		else delta = min(delta, 1LL*c[u][v]-f[u][v]);
		v = u;
	}
	v = t;
	while (v!=s) {
		int u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
		v = u;
	}
	res += delta*d[t];
	return delta;
}

bool findway(int u) {
	if (u==t) {path.push_back(t); return true;}
	REP(i, a[u].sz()) {
		int v = a[u][i].fi;
		if (f[u][v]<=0) continue;
		f[u][v]--;
		if (findway(v)) {
			path.push_back(u);
			return true;
		}
		++f[u][v];
	}
	return false;
}

int main() {
    //freopen("kway.inp", "r", stdin);
    //freopen("kway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k >> s >> t;
	int tmp = k;
	FOR(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back(ii(v, w));
		a[v].push_back(ii(u, w));
		c[u][v]++; c[v][u]++;
	}
	while (findpath()) {
		if (k==0) break;
		k -= incFlow();
	}
	if (k>0) cout << -1;
	else {
		cout << res << '\n';
		FOR(i, 1, tmp) {
			path.clear();
			findway(s);
			cout << path.sz() << ' ';
			reverse(path.begin(), path.end());
			REP(i, path.sz()) cout << path[i] << ' ';
			cout << '\n';
		}
	}
}
