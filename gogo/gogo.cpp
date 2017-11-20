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

#define maxn
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

int id(int x, int y) {return a*(n-1) + y;}
int findset(int u) {return lab[u]<=0 ? u : lab[u]=findset(lab[u]);}
void uni(int s, int t) {
	if (s==t) return;
	if (lab[s]<lab[t]) {
		lab[t] = s; 
		cnt[s] += cnt[t];
	}
	else if (lab[s]>lab[t]) {
		lab[s] = t;
		cnt[t] += cnt[s];
	}
	else {
		lab[s] = t;
		lab[t]--;
		cnt[t] += cnt[s];
	}
}

void Remove(int x, int y, char c) {
	cnt[id(x, y)] = 0; lab[id(x, y)] = 0;
	REP(i, 4) {
		int p = x + mv[i].fi, q = y + mv[i].se;
		if (a[p][q]==c) Remove(p, q, c);
		else if (a[p][q]!=-1) --cnt[findset(id(p, q))];
	}
}

void process(int x, int y, int color) {
	a[x][y] = color;
	REP(i, 4) {
		int p = x + mv[i].fi, q = y + mv[i].se;
		if (a[p][q]==-1) ++cnt[findset(id(x, y))];
		else if (a[p][q]==color) {
			uni(findset(id(x, y)), findset(id(p, q)));
		}
		else {
			--cnt[findset(id(p, q))];
			if (cnt[findset(id(p, q))]==0)
				Remove(p, q);
		}
	}
}

int main() {
    freopen("gogo", "r", stdin);
    //freopen("", "w", stdout);
	while (cin >> n >> m) {
		if (n==0) break;
		memset(a, -1, sizeof(a));
		memset(lab, 0, sizeof(lab));
		while (m--) {
			char c;
			int x, y;
			scanf("%c(%d,%d)\n", &c, &y, &x);
			x += (n/2+1); y += (n/2+1);
			process(x, y, c-'0');
		}
		FOR(i, 1, n) FOR(j, 1, n) {
			REP(i, <F10>
		}
	}
}
