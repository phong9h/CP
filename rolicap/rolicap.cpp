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
#define PR0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i].fi << ' ' << A[i].se << ' '; cerr << '\n';}
typedef long long ll;
typedef double db;
typedef pair<int, int> ii;
typedef vector<int> vi;
const ll inf = 1e18;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n;
ii a[maxn];
vector<ii> U, D;

bool cw(ii a, ii b, ii c) {
	return a.fi*(b.se-c.se) + b.fi*(c.se-a.se) + c.fi*(a.se-b.se)<=0;
}

bool ccw(ii a, ii b, ii c) {
	return a.fi*(b.se-c.se) + b.fi*(c.se-a.se) + c.fi*(a.se-b.se)>=0;
}

void convex_hull() {
	sort(a+1, a+n+1);
	ii p = a[1], q = a[n];
	U.push_back(p);
	D.push_back(p);
	FOR(i, 2, n) {
		if (i==n || cw(p, a[i], q)) {
			while (U.sz()>1 && !cw(U[U.sz()-2], U[U.sz()-1], a[i]))
				U.pop_back();
			U.push_back(a[i]);
		}
		if (i==n || ccw(p, a[i], q)) {
			while (D.sz()>1 && !ccw(D[D.sz()-2], D[D.sz()-1], a[i]))
				D.pop_back();
			D.push_back(a[i]);
		}
	}
}

ll dist(ii a, ii b) {
	return (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se);
}

ll maxDist(int id) {
	int l=0, r = D.sz()-1, mid = (l+r)/2;
	while (l!=mid && mid!=r) {
		if (mid==0 || dist(a[id], D[mid])>=dist(a[id], D[mid-1])) l = mid;
		else r = mid;
		mid = (l+r)/2;
	}
	ll res = 0;
	FOR(i, l, r) {
		res = max(res, dist(a[id], D[i]));
	}
	return res;
}

int main() {
    //freopen("rolicap.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		U.clear(); D.clear();
		cin >> n;
		FOR(i, 1, n) {
			cin >> a[i].fi >> a[i].se;
		}
		convex_hull();
		//PR0(D, D.sz());
		ll res = -inf;
		FOR(i, 1, n) {
			res = max(res, maxDist(i));
		}
		cout << res << '\n';
	}
}
