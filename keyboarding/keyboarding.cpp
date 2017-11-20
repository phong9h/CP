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

#define maxn 52
#define maxlen 1002
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

struct node {
	int x, y, prf;
	node() {}
	node(int a, int b, int c) {x = a; y = b; prf = c;}
};

int n, m, d[maxn][maxn][maxlen];
ii next[maxn][maxn][4];
string s;
char a[maxn][maxn];
ii mv[] = {ii(-1, 0), ii(1, 0), ii(0, -1), ii(0, 1)};
queue<node> qu;

void bfs() {
	memset(d, -1, sizeof(d));
	d[1][1][a[1][1]==s[0]] = 0;
	qu.push(node(1, 1, a[1][1]==s[0]));
	while (qu.sz()) {
		int x = qu.front().x, y = qu.front().y, prf = qu.front().prf;
		qu.pop();
		REP(dir, 4) {
			int p = next[x][y][dir].fi, q = next[x][y][dir].se, prf2 = prf;
			if (p==0 || q==0 || p==m+1 || q==n+1) continue;
			if (prf<(int)s.sz() && a[p][q]==s[prf]) ++prf2;
			if (d[p][q][prf2]==-1) {
				d[p][q][prf2] = d[x][y][prf] + 1;
				qu.push(node(p, q, prf2));
			}
		}
	}
	int res = inf;
	FOR(i, 1, m) FOR(j, 1, n) {
		if (a[i][j]=='*' && d[i][j][s.sz()]!=-1)
			res = min(res, d[i][j][s.sz()] + (int)s.sz() + 1);	
	}
	DB(d[6][4][2]);
	cout << res;
}

int main() {
    freopen("keyboarding.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
	cin >> s;
	FOR(i, 1, m) FOR(j, 1, n) FOR(dir, 0, 3) {
		int x = i, y = j;
		while (x>0 && y>0 && x<=m && y<=n && a[x][y]==a[i][j]) {
			x += mv[dir].fi, y += mv[dir].se;
		}
		next[i][j][dir] = ii(x, y);
	}
	DB(next[1][1][1].fi); DB(next[1][1][1].se);
	bfs();
}
