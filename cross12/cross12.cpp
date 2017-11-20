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

int n, m, a[maxn], prev[maxn], T[maxn];
string s;

int calc(int r) {
	int nStep = 0, curPos = 0;
	while (curPos<=m && nStep<=m) {
		++nStep;
		if (curPos+r>m) return nStep;
		curPos = prev[curPos+r];
	}
}

int main() {
    //freopen("cross12.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	cin >> s;
	s = '0' + s;
	REP(i, s.sz()) {
		if (s[i]=='0') prev[i] = i;
		else prev[i] = prev[i-1];
	}
	FOR(i, 1, 100) T[i] = calc(i);
	FOR(i, 1, n) a[i] = T[a[i]];
	sort(a+1, a+n+1);
	int f1 = a[1], f2 = a[2];
	FOR(i, 3, n) {
		int fi = min(a[1] + a[i] + f2, a[1] + 2*a[2] + a[i] + f1);
		f1 = f2;
		f2 = fi;
	}
	cout << f2;
}
