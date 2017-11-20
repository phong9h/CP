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

#define maxn 1000002
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

struct pack {
	ll val;
	int u, id;
	pack() {}
	pack(ll a, int b, int c) {
		val = a; u = b; id = c;
	}
};

int n, m, cnt, st[maxn], fn[maxn], tr[8*maxn], a[maxn*2], w[maxn];
ll l[maxn], res[maxn];
ii q[maxn];
vector<ii> b;
vector<pack> query;

bool cmp(pack a, pack b) {return a.val<b.val;}

int level(int u) {return l[u]>-1 ? l[u] : l[u]=level(u/2)+w[u];}

void eulerTour(int u) {
	if (u>n) return;
	a[++cnt] = l[u]; st[u] = cnt;
	eulerTour(u*2); eulerTour(u*2+1);
	a[++cnt] = l[u]; fn[u] = cnt;
}

void update(int pos, int val, int l=1, int r=cnt, int id=1) {
	if (pos<l || pos>r) return;
	if (pos==l && r==pos) {
		tr[id] += val;
		return;
	}
	int mid = (l+r)/2;
	update(pos, val, l, mid, id*2);
	update(pos, val, mid+1, r, id*2+1);
	tr[id] = tr[id*2] + tr[id*2+1];
}

ll get(int u, int v, int l=1, int r=cnt, int id=1) {
	if (v<l || u>r) return 0;
	if (u<=l && r<=v) return tr[id];
	int mid = (l+r)/2;
	return get(u, v, l, mid, id*2) + get(u, v, mid+1, r, id*2+1);
}

void solve() {
	sort(query.begin(), query.end(), cmp);
	FOR(i, 1, cnt) b.push_back(ii(a[i], i));
	sort(b.begin(), b.end(), cmp1);

}

int main() {
    freopen("bintree.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	FOR(i, 1, n-1) cin >> w[i+1];
	memset(l, -1, sizeof(l));
	l[1] = 0;
	FOR(i, 1, n) level(i);
	eulerTour(1);
	FOR(i, 1, m) {
		cin >> q[i].fi >> q[i].se;
		int A = q[i].fi, H = q[i].se;
		ll tmp = 0;
		while (A>0 && tmp<=H) {
			query.push_back(pack(H+l[A]-tmp, A, i));
			tmp += w[A];
			A /= 2;
		}
	}
	solve();
}
