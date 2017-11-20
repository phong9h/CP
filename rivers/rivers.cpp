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

#define maxn 102
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

int n, k, p[maxn], l[maxn];
ii par[maxn];
ll f[maxn][maxn/2][maxn][maxn];
vector<int> a[maxn];

int level(int u) {return l[u]>-1 ? l[u] : l[u]=level(par[u].fi)+par[u].se;}

int dist(int u, int v) {
	return abs(l[v]-l[u]);
}

ll dp(int u, int x, int t, int last) {
	if (x<0) return inf;
	if (t==a[u].sz()) {
		return min(min(inf, dp(u, x, t-1, last) + 1LL*dist(u, last)*p[u]),
					dp(u, x-1, t-1, u));
	}
	if (t==-1) return 0;
	if (f[u][x][t][last]>-1) return f[u][x][t][last];
	ll res = inf;
	int v = a[u][t];
	FOR(x2, 0, x) {
		res = min(res, dp(u, x-x2, t-1, last) + dp(v, x2, int(a[v].sz()), last));
	}
	return f[u][x][t][last]=res;
}

int main() {
    //freopen("rivers.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> p[i] >> par[i].fi >> par[i].se;
		a[par[i].fi].push_back(i);
	}
	memset(l, -1, sizeof(l));
	l[0] = 0;
	FOR(i, 1, n) level(i);
	memset(f, -1, sizeof(f));
	//DB(dp(2, 0, 2, 2));
	cout << dp(0, k, int(a[0].sz()), 0);
}
