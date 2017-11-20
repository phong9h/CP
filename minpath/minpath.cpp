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
typedef pair<ll, int> ii;
typedef vector<int> vi;
const ll inf = 1e18;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, m, s, t;
ll d[maxn];
vector<ii> a[maxn], b[maxn];
priority_queue<ii, vector<ii>, greater<ii> > pq;

void dijkstra() {
	FOR(i, 1, n) d[i] = inf;
	pq.push(ii(d[t]=0, t));
	while (pq.sz()) {
		int u = pq.top().se;
		ll du = pq.top().fi; pq.pop();
		REP(i, a[u].sz()) {
			int v = a[u][i].se, w = a[u][i].fi;
			if (d[v]>d[u]+w)	{
				d[v] = d[u] + w;
				pq.push(ii(d[v], v));
			}
		}
	}
}

void printResult(int s) {
	cout << s << ' ';
	int pos = n+1;
	REP(i, b[s].sz()) {
		int v = b[s][i].se, w = b[s][i].fi;
		if (d[s]==d[v]+w && v<pos) pos = v;
	}
	if (pos!=n+1) printResult(pos);
}

int main() {
    //freopen("minpath.inp", "r", stdin);
    //freopen("minpath.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	FOR(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		a[v].push_back(ii(w, u));
		b[u].push_back(ii(w, v));
	}
	cin >> s >> t;
	dijkstra();
	cout << d[s] << '\n';
//	printResult(s);
	while (true) {
		int pos = n+1;
		cout << s << ' ';
		if (s==t) break;
		REP(i, b[s].sz()) {
			int v = b[s][i].se, w = b[s][i].fi;
			if (d[s]==d[v]+w && v<pos) pos = v;
		}
		s = pos;
	}
}
