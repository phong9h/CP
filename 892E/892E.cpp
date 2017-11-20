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

#define maxn 500002
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

struct edge {
	int u, v, w, id;	
} e[maxn], x[maxn];

int n, m, q, lab[maxn];
ii p[maxn];

bool cmp(edge a, edge b) {return a.w<b.w;}
bool cmp2(edge a, edge b) {return a.id<b.id;}

int findset(int u) {return lab[u]<=0 ? u : lab[u]=findset(lab[u]);}
void uni(int s, int t) {
	if (s==t) return;
	if (lab[s]<lab[t]) lab[t] = s;
	else if (lab[s]>lab[t]) lab[s] = t;
	else {lab[s] = t; lab[t]--;}
}

bool check(int l, int r) {
	FOR(i, l, r) {
		lab[p[x[i].id].fi] = lab[p[x[i].id].se] = 0;
	}
	FOR(i, l, r) {
		int s = findset(p[x[i].id].fi), t = findset(p[x[i].id].se);
		if (s==t) return false;
		uni(s, t);
	}
	return true;
}

int main() {
    //freopen("892E.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].id = i;
	}
	sort(e+1, e+m+1, cmp);
	for (int i=1; i<=m;) {
		int j = i;
		while (j+1<=m && e[j+1].w==e[i].w) ++j;
		FOR(t, i, j) {
			int h = findset(e[t].u), k = findset(e[t].v);
			p[e[t].id] = ii(min(h, k), max(h, k));
		}
		FOR(t, i, j) uni(findset(e[t].u), findset(e[t].v));
		i = j+1;
	}
	int q; cin >> q;
	sort(e+1, e+m+1, cmp2);
	while (q--) {
		int k; cin >> k;
		FOR(i, 1, k) {
			int id; cin >> id;
			x[i] = e[id];
		}
		bool ok = true;
		sort(x+1, x+k+1, cmp);
		for (int i=1; i<=k; ) {
			int j = i;
			while (j+1<=k && x[j+1].w==x[i].w) ++j;
			ok = ok && check(i, j);
			i = j+1;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}
