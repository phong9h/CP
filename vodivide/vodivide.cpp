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

#define maxn 5002
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

struct coin {
	int a, b, id;
} c[maxn];

int n, f[maxn][maxn];
vector<int> p;

bool cmp(coin a, coin b) {return a.a>b.a;}

int dp(int pos, int t) {
	if (pos==n+1) return 0;
	if (f[pos][t]>-1) return f[pos][t];
	f[pos][t] = dp(pos+1, t+1);
	if (t>0) f[pos][t] = max(f[pos][t], dp(pos+1, t-1)+c[pos].b);
	return f[pos][t];
}

void trace(int pos, int t) {
	if (pos==n+1) return;
	if (f[pos][t]==dp(pos+1, t+1)) {
		p.push_back(c[pos].id);
		return trace(pos+1, t+1);
	}
	cout << c[pos].id << ' ' << p.back() << '\n';
	p.pop_back();
	trace(pos+1, t-1);
}

int main() {
    //freopen("vodivide.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> c[i].a;
	FOR(i, 1, n) cin >> c[i].b;
	FOR(i, 1, n) c[i].id = i;
	sort(c+1, c+n+1, cmp);
	memset(f, -1, sizeof(f));
	cout << dp(1, 0) << '\n';
	trace(1, 0);
}
