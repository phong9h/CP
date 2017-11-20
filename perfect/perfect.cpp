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

bool check_1(int i) {
	return ok_1[i+1] && ok_2[i+1] && ok_3[i+1];
}

bool check_2(int i) {
	return !((MINL[i]<b && b<MAXR[i+1]) || (MINL[i]<MINB[i+1]) || ()
}

void init() {
	FOR(i, 1, n) {
		MINL[i] = min(MINL[i-1], a[i]);
		MAXL[i] = max(MAXL[i], a[i]);
	}
	FORD(i, n, 1) {
		MINR[i] = min(MINR[i+1], a[i]);
		MINB[i] = min(MINB[i+1], a[i] > b ? a[i] : inf);
		MAXR[i] = max(MAXR[i+1], a[i]);
	}
	memset(ok_1, true, sizeof(ok_1));
	FORD(i, n, 1) {
		if (a[i]>b && MINR[i+1]<a[i])
			ok_1[i] = false;
		if (a[i]>b && MAXR[i+1]>a[i])
			ok_2[i] = false;
		if (a[i]<b && MAXR[i+1]>b)
			ok_3[i] = false;
	}
}

int main() {
    freopen("perfect.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];	
	FOR(i, 0, n) {
		res += (check_1(i) && check_2(i) && check_3(i));
	}
}
