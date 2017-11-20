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

int n, m, s, t, q, c[maxn][maxn], f[maxn][maxn], d[maxn], visited[maxn], res[maxn];
ii e[maxn];
vector<int> a[maxn];
queue<int> qu;

bool bfs() {
	memset(d, -1, sizeof(d));
	d[s] = 0;
	qu.push(s);
	while (qu.sz()) {
		int u = qu.front();
		//DB(u);
		qu.pop();
		REP(i, a[u].sz()) {
			int v = a[u][i];
			if (c[u][v]>f[u][v] && d[v]==-1) {
				d[v] = d[u] + 1;
				qu.push(v);
			}
		}
	}
	return d[t]>-1;
}

int visit(int u, int MIN) {
	if (u==t) return MIN;
	if (visited[u]!=q) visited[u] = q;
	else return 0;
	REP(i, a[u].sz()) {
		int v = a[u][i];
		if (d[v]==d[u]+1 && c[u][v]>f[u][v]) {
			int x = visit(v, min(MIN, c[u][v]-f[u][v]));
			if (x>0) {
				f[u][v] += x;
				f[v][u] -= x;
				return x;
			}
		}
	}
	return 0;
}

bool check(int x) {
	memset(f, 0, sizeof(f));
	FOR(i, 1, n) c[i][t] = x;
	int maxFlow = 0;
	while (bfs()) {
		while (true) {
			++q;
			int x = visit(s, inf);
			if (x==0) break;
			maxFlow += x;
		}
	}
	FOR(i, n+1, m+n) {
		REP(j, a[i].sz()) {
			int v = a[i][j];
			if (f[i][v]==1) res[i-n] = v;
		}
	}
	//DB(maxFlow);
	return maxFlow==m;
}

void bisect() {
	int l=1, r=m, mid = (l+r)/2;
	while (l!=mid && mid!=r) {
		if (check(mid)) r = mid;
		else l = mid;
		mid = (l+r)/2;
	}
	FOR(i, l, r) {
		if (check(i)) {
			cout << i << '\n';
			FOR(i, 1, m) {
				if (e[i].fi==res[i]) cout << res[i] << ' ' << e[i].se << '\n';
				else cout << res[i] << ' ' << e[i].fi << '\n';
			}
			return;
		}
	}
}

int main() {
    //freopen("souvernir.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	FOR(i, 1, m) {
		int u, v; cin >> u >> v;
		e[i] = ii(u, v);
		a[i+n].push_back(u);
		a[i+n].push_back(v);
		a[u].push_back(i+n);
		a[v].push_back(i+n);
		c[i+n][u] = c[i+n][v] = 1;
	}
	if (m==0) {cout << 0; return 0;}
	s = m+n+1; t = m+n+2;
	FOR(i, n+1, m+n) {
		a[s].push_back(i);
		a[i].push_back(s);
	}
	FOR(i, 1, n) {
		a[i].push_back(t);
		a[t].push_back(i);
	}
	FOR(i, n+1, m+n) c[s][i] = 1;
	bisect();
}
