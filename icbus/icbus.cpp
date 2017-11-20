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
using namespace std;

#define maxn 5002
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
#define PR0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i].se << ' '; cerr << '\n';}
typedef long long ll;
typedef double db;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 1e9;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, m, d[maxn];
ii p[maxn];
vector<ii> b[maxn];
vector<int> a[maxn];
queue<int> qu;
priority_queue<ii, vector<ii>, greater<ii> > pq;

void bfs(int st) {
	qu.push(st);
	d[st] = 1;
	while (qu.sz()) {
		int u = qu.front(); qu.pop();
		REP(i, a[u].sz()) {
			int v = a[u][i];
			if (d[v]==0) {
				d[v] = d[u] + 1;
				qu.push(v);
			}
		}
	}
	FOR(i, 1, n) {
		if (d[i]>0 && d[i]-1<=p[st].se) b[st].push_back(ii(p[st].fi, i));
	}
}

void dijkstra() {
	FOR(i, 1, n) d[i] = inf;
	pq.push(ii(d[1]=0, 1));
	while (pq.sz()) {
		int u = pq.top().se, du = pq.top().fi;
		pq.pop();
		if (du!=d[u]) continue;
		REP(i, b[u].sz()) {
			int v = b[u][i].se, w = b[u][i].fi;
			if (d[v]>d[u]+w) pq.push(ii(d[v]=d[u]+w, v));
		}
	}
	cout << d[n];
}

int main() {
    freopen("icbus.inp", "r", stdin);
    freopen("icbus.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	FOR(i, 1, n) cin >> p[i].fi >> p[i].se;
	FOR(i, 1, m) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	FOR(i, 1, n) bfs(i);
	dijkstra();
}
