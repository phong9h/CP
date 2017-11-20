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

#define maxn 10002
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

int n;
ii a[maxn], seg[maxn];
priority_queue<int, vector<int>, greater<int> > pq;

bool check(int v) {
	FOR(i, 1, n) {
		seg[i] = ii(a[i].fi-v/a[i].se, a[i].fi+v/a[i].se);
	}
	sort(seg+1, seg+n+1);
	while (pq.sz()) pq.pop();
	int head = 0;
	FOR(i, 1, n) {
		while (head+1<=n && seg[head+1].fi<=i) {
			pq.push(seg[++head].se);
		}
		if (pq.empty() || pq.top()<i) return false;
		pq.pop();
	}
	return true;
}

void bisect() {
	int l=1, r=inf, mid = (l+r)/2;
	while (l!=mid && mid!=r) {
		if (check(mid)) r = mid;
		else l = mid;
		mid = (l+r)/2;
	}
	FOR(i, l, r) {
		if (check(i)) {
			cout << i;
			return;
		}
	}
}

int main() {
    //freopen("move12.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> a[i].fi >> a[i].se;
	bisect();
}
