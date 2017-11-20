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
const int inf = 1e9;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, k;
ll f[maxn][maxn], ps[maxn][maxn], t;

void solve(int pos, int x, ll t) {
	if (pos==0) return;
	if (t<f[pos][x]) {
		solve(pos-1, x-1, t);
		cout << 'T';
	}
	else {
		solve(pos-1, x, t-f[pos][x]);
		cout << 'B';
	}
}

int main() {
    freopen("light.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> t;
	FOR(i, 1, n) FOR(j, 1, i) {
		f[i][j] = ps[i-1][j-1] - ps[j-1][j-1] + 1;
		ps[i][j] = ps[i-1][j] + f[i][j];
	}
	ll tmp = 0;
	FORD(i, n, n-k+1) tmp += f[i][n-k];
	t = t%tmp;
	solve(n, n-k, t-1);
}
