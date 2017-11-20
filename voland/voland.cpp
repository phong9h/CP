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
 
#define maxn 1007
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
const int offset = 1007;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}
 
int m, n, r, c, k, a[maxn][maxn], b[maxn+offset][maxn*2];
ii mv[] = {ii(-1, -1), ii(1, -1), ii(-1, 1), ii(1, 1)};
ll d[maxn][maxn], ps[maxn+offset][maxn*2], d1[maxn+offset][4], d2[maxn*2][4];
 
ll get(int x1, int y1, int x2, int y2) {
	int yMIN = min(y1, y2), yMAX = max(y1, y2);
	int xMIN = min(x1, x2), xMAX = max(x1, x2);
	x1 = xMAX; x2 = xMIN;
	y1 = yMAX; y2 = yMIN;
	return ps[x1][y1] - ps[x1][y2-1] - ps[x2-1][y1] + ps[x2-1][y2-1];
}
 
void rhombus() {
	FOR(i, 1-n+offset, m-1+offset) FOR(j, 2, m+n)
		ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + b[i][j];
	FOR(i, 1, m) FOR(j, 1, n) {
		if (i-k>0 && i+k<=m && j-k>0 && j+k<=n)
			d[i][j] = get(i-j+k+offset, i+j+k, i-j-k+offset, i+j-k);
		else d[i][j] = -inf;
	}
}
 
void rectangle() {
	FOR(i, 0, m) FOR(j, 0, n) REP(dir, 4)
		d1[i+j][dir] = d2[i-j+offset][dir] = -inf;
	FOR(i, 1, m) FOR(j, 1, n) {
		ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i][j];
	}
	FOR(x1, 1, m) FOR(y1, 1, n) REP(dir, 4) {
		int x2 = x1 + mv[dir].fi*(r-1), y2 = y1 + mv[dir].se*(c-1);
	   	if (x2>0 && x2<=m && y2>0 && y2<=n) {
	   		d1[x1+y1][dir] = max(d1[x1+y1][dir], get(x1, y1, x2, y2));
			d2[x1-y1+offset][dir] = max(d2[x1-y1+offset][dir], get(x1, y1, x2, y2));
		}
	}
	FORD(i, m+n-1, 2) d1[i][3] = max(d1[i][3], d1[i+1][3]);
	FOR(i, 3, m+n) d1[i][0] = max(d1[i][0], d1[i-1][0]);
	FORD(i, m-2+offset, 1-n+offset) d2[i][1] = max(d2[i][1], d2[i+1][1]);
	FOR(i, 2-n+offset, m-1+offset) d2[i][2] = max(d2[i][2], d2[i-1][2]);
}
 
void solve() {
	ll res = -inf;
	FOR(i, 1, m) FOR(j, 1, n) REP(dir, 4) {
		if (d[i][j]==-inf) continue;
		if (d1[i+j+k+1][3]!=-inf) res = max(res, d[i][j]+d1[i+j+k+1][3]);
		if (d1[i+j-k-1][0]!=-inf) res = max(res, d[i][j]+d1[i+j-k-1][0]);
		if (d2[i-j+offset+k+1][1]!=-inf) res = max(res, d[i][j]+d2[i-j+offset+k+1][1]);
		if (d2[i-j+offset-k-1][2]!=-inf) res = max(res, d[i][j]+d2[i-j+offset-k-1][2]);
	}
	if (res>-inf) cout << res;
	else cout << "no solution";
}
 
int main() {
    freopen("voland.inp", "r", stdin);
    freopen("voland.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> r >> c >> k;
	FOR(i, 1, m) FOR(j, 1, n) {
		cin >> a[i][j];
		b[i-j+offset][i+j] = a[i][j];
	}
	rhombus();
	rectangle();
	solve();
}
