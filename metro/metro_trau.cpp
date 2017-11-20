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
#include <map>
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
typedef pair<ll, ii> iii;
typedef vector<int> vi;
const ll inf = 1e18;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, m, s, t, alpha;
vector<iii> a[maxn];
priority_queue<iii, vector<iii>, greater<iii> > pq;
map<ii, ll> d;

void dijkstra() {
	pq.push(iii(0, ii(s, -1)));
	ll res = inf;
	while (pq.sz()) {
		ii u = pq.top().se;
		ll du = pq.top().fi; pq.pop();
		if (du!=d[u]) continue;
		REP(i, a[u.fi].sz()) {
			ii v = a[u.fi][i].se;
		   	int	w = a[u.fi][i].fi;
			int cost = u.se==-1 ? 0 : u.se*alpha+v.se;
			if (d.find(v)==d.end() || d[v]>d[u]+w+cost) {
				pq.push(iii(d[v]=d[u]+w+cost, v));
				if (v.fi==t) res = min(res, d[v]);
			}
		}
	}
	if (res!=inf) cout << res;
	else cout << -1;
}

int main() {
    //freopen("metro.inp", "r", stdin);
    //freopen("", "w", stdout);
    //ios::sync_with_stdio(0); cin.tie(0);
	//cin >> n >> m >> s >> t >> alpha;
	scanf("%d%d%d%d%d", &n, &m, &s, &t, &alpha);
	FOR(i, 1, m) {
		//int u, v, w; cin >> u >> v >> w;
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u].push_back(iii(w, ii(v, i)));
	}
	dijkstra();
}
