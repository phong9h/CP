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

#define maxn 100002
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

int n, m, d1[maxn], d2[maxn], s, t;
vector<int> a[maxn], b[maxn], c[maxn], res;
bool visited[maxn], avail[maxn];
queue<int> qu;

void bfs(int st, int d[], vector<int> a[maxn]) {
	qu.push(st);
	d[st] = 1;
	while (qu.sz()) {
		int u = qu.front(); qu.pop();
		REP(i, a[u].sz()) {
			int v = a[u][i];
			if (d[v]==0) {
				d[v] = d[u]+1; 
				qu.push(v);
			}
		}
	}
}

void visit(int u) {
	visited[u] = true;
	REP(i, b[u].sz()) {
		int v = b[u][i];
		if (!visited[v]) visit(v);
	}
}

bool solve(int u) {
	if (d2[u]==0 || !avail[u]) return false;
	if (u==t) {res.push_back(u); return true;}
	avail[u] = false;
	REP(i, a[u].sz()) {
		int v = a[u][i];
		if (solve(v)) {
			res.push_back(u);
			return true;
		}
	}
	return false;
}

int main() {
    freopen("gsearch.inp", "r", stdin);
    //freopen("gsearch.out", "w", stdout);
	scanf("%d%d", &n, &m);
	FOR(i, 1, m) {
		int u, v; scanf("%d%d", &u, &v);
		a[u].push_back(v);
		b[u].push_back(v);
		b[v].push_back(u);
		c[v].push_back(u);
	}
	scanf("%d%d", &s, &t);
	int cnt = 0;
	FOR(i, 1, n) {
		if (!visited[i]) {
			++cnt;
			visit(i);
		}
	}
	bfs(s, d1, a);
	bfs(t, d2, c);
	cout << cnt << '\n' << d1[t] << '\n';
	memset(avail, true, sizeof(avail));
	FOR(i, 1, n) sort(a[i].begin(), a[i].end());
	solve(s);
	reverse(res.begin(), res.end());
	cout << res.sz() << '\n';
	REP(i, res.sz()) cout << res[i] << ' ';
}
