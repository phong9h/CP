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
const int MOD = 1000000007;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, a[maxn], g[maxn][maxn], b[maxn], POW2[maxn];
map<int, int> id;
bool avail[maxn];

void compress() {
	sort(b+1, b+n+1);
	FOR(i, 1, n) id[b[i]] = i;
}

int solve(int pos) {
	if (pos==n+1) return 0;
	int res = 0;
	FOR(i, 1, a[pos]-1) {
		if (avail[i] && i-g[pos][i]-1<2)
			res = (res + POW2[max(0, n-pos-1)])%MOD;
	}
	avail[a[pos]] = false;
	return (res + solve(pos+1))%MOD;
}

int main() {
    //freopen("barcode.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> b[i];
	compress();
	POW2[0] = 1;
	FOR(i, 1, n) POW2[i] = POW2[i-1]*2%MOD;
	int m; cin >> m;
	while (m--) {
		FOR(i, 1, n) cin >> a[i];
		FOR(i, 1, n) a[i] = id[a[i]];
		memset(avail, true, sizeof(avail));
		FOR(i, 1, n) FOR(j, 1, n) {
			g[i][j] = g[i-1][j] + (i>1 && id[a[i-1]]<j);
		}
		cout << solve(1)+1 << '\n';
	}
}
