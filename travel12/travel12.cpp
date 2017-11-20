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
#include <bitset>
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

int n, m;
vector<int> a[maxn];
bitset<maxn> bs[maxn];

int main() {
    //freopen("travel12.inp", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d%d", &n, &m);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		if (!bs[u].test(v)) {
			a[u].push_back(v);
			a[v].push_back(u);
			bs[u].set(v);
			bs[v].set(u);
		}
	}
	FOR(u, 1, n) FOR(v, u+1, n) {
		int x = 0;
		REP(i, a[u].sz()) {
			int t = a[u][i];
			if (bs[v].test(t)) {
				if (x!=0) {
					printf("%d %d %d %d", u, x, v, t);
					return 0;
				}
				x = t;
			}
		}
	}
	printf("-1");
}
