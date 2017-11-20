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

#define maxn 1002
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

int n, h, k, a[maxn], b[maxn];

bool check(int a[], int n) {
	FOR(i, 1, n) FOR(j, i+1, n) FOR(k, j+1, n) {
		if ((a[k]<a[i] && a[i]<a[j]) || (a[j]<a[k] && a[k]<a[i])) {
			//DB(a[i]); DB(a[j]); DB(a[k]);
			return false;
		}
	}
	REP(i, 1<<n) {
		if (__builtin_popcount(i)!=k) continue;
		int prev = inf;
		bool ok = false;
		FOR(j, 1, n) {
			if (getbit(i, j)==1) {
				if (a[j]>prev) ok = true;
				prev = a[j];
			}
		}
		if (!ok) {
			//DB(i);
			return false;
		}
	}
	return true;
}

void solve_1() {
	int res = 0;
	FOR(i, 0, n) {
		FOR(t, 1, i) b[t] = a[t];
		FOR(t, i+2, n+1) b[t] = a[t-1];
		b[i+1] = h;
		//PR(b, n+1);
		res += check(b, n+1);
	}
	cout << res << '\n';
}

void solve_2() {
	int cnt = 0;
	FOR(i, 1, n+1) a[i] = i;
	while (true) {
		cnt += check(a, n+1);
		if (!next_permutation(a+1, a+n+2)) break;
	}
	cout << cnt;
}

int main() {
    freopen("treelinek.inp", "r", stdin);
    freopen("treelinek.ans", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> h >> k;
	FOR(i, 1, n) cin >> a[i];
	//cout << check(a, n);
	solve_1();
	solve_2();
}

