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

struct edge {
	int u, v, w;
} e[maxn];
int n, m, lab[maxn];
ll res;
vector<ii> mst;

bool cmp(edge a, edge b) {
	if (a.w!=b.w)
		return a.w<b.w;
	return ii(a.u, a.v)<ii(b.u, b.v);
}

int findset(int u) {return lab[u]<=0 ? u : lab[u]=findset(lab[u]);}
void uni(int s, int t) {
	if (lab[s]<lab[t]) lab[t] = s;
	else if (lab[s]>lab[t]) lab[s] = t;
	else {lab[s] = t; lab[t]--;}
}

void process(edge e) {
	int s = findset(e.u), t = findset(e.v);
	if (s==t) return;
	uni(s, t);
	res += e.w;
	mst.push_back(ii(e.u, e.v));
}

int main() {
    freopen("mst.inp", "r", stdin);
    //freopen("mst.out", "w", stdout);
	scanf("%d%d", &n, &m);
	FOR(i, 1, m) {
		int u, v;
		scanf("%d%d%d", &u, &v, &e[i].w);
		e[i].u = min(u, v);
		e[i].v = max(u, v);
	}
	sort(e+1, e+m+1, cmp);
	FOR(i, 1, m) process(e[i]);
	sort(mst.begin(), mst.end());
	printf("%I64d\n", res);
	REP(i, mst.sz()) printf("%d %d ", mst[i].fi, mst[i].se);
}
