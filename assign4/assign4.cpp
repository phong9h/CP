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

#define maxn 202
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
#define next __next
#define prev __prev
#define sz size
#define DB(X) {cerr << #X << " = " << X << '\n';}
#define PR(A, n) {cerr << #A << " = "; FOR(i, 1, n) cerr << A[i] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i] << ' '; cerr << '\n';}
typedef long long ll;
typedef double db;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 1e9;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, m, s, t, c[maxn][maxn], f[maxn][maxn], w[maxn][maxn], d[maxn], trace[maxn], res;
bool inqueue[maxn];
queue<int> qu;

bool findPath() {
	FOR(i, 0, m+n+1) d[i] = inf;
	memset(inqueue, false, sizeof(inqueue));
	inqueue[s] = true;
	qu.push(s);
	d[s] = 0;
	while (qu.sz()) {
		int u = qu.front(); qu.pop();
		inqueue[u] = false;
		FOR(v, 0, m+n+1) {
			if (c[u][v]>f[u][v] && d[v]>d[u] + (f[u][v]>=0 ? w[u][v] : -w[u][v])) {
				d[v] = d[u] + (f[u][v]>=0 ? w[u][v] : -w[u][v]);
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

void incFlow() {
	int delta = inf;
	for (int v = t; v!=s; v = trace[v]) {
		if (f[trace[v]][v]<0) delta = min(delta, -f[trace[v]][v]);
		else delta = min(delta, c[trace[v]][v]-f[trace[v]][v]);
	}
	for (int v = t; v!=s; v = trace[v]) {
		f[trace[v]][v] += delta;
		f[v][trace[v]] -= delta;
	}
	res += d[t]*delta;
}

void solve() {
	cin >> m >> n;
	memset(c, 0, sizeof(c));
	FOR(i, 1, m) FOR(j, m+1, n+m) c[i][j] = inf;
	memset(f, 0, sizeof(f));
	memset(w, 0, sizeof(w));
	res = 0;
	t = m+n+1;
	FOR(i, 1, m) cin >> c[s][i];
	FOR(i, 1, n) cin >> c[i+m][t];
	FOR(i, 1, m) FOR(j, 1, n) cin >> w[i][j+m];
	while (findPath())
        incFlow();
	cout << res;
}

int main() {
    freopen("assign4.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	int nTest; cin >> nTest;
	while (nTest--) solve();
}
