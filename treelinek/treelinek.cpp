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
const ll MOD = 1000000007;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, k, a[maxn];
ll f[maxn], ps[maxn];
set<ii> s;

void compress() {
	FOR(i, 1, n) s.insert(ii(a[i], i));
	int tmp = 0;
	for (set<ii>::iterator it=s.begin(); it!=s.end(); ++it) {
		a[it->se] = ++tmp;
	}
}

bool check() {
	int prev = -1, MAX = n, prev_2 = a[n], cnt = 0;
	if (k==1) return false;
	FORD(i, n, 1) {
		if (prev!=-1 && a[i]!=prev+1) {
			return false;
		}
		prev = a[i];
		++cnt;
		if (a[i]==MAX) {
			if (cnt>=k) return false;
			prev = -1;
			cnt = 0;
			MAX = prev_2 - 1;
			prev_2 = a[i-1];
		}
	}
	return true;
}

void solve_1() {
	if (k==1) {cout << 0 << '\n'; return;}
	if (k==2) {cout << 1 << '\n'; return;}
	int MAX = 0, pos;
	bool ok = true;
	//PR(a, n);
	FOR(i, 1, n) {
		if (a[i]>MAX) {
			MAX = a[i];
			pos = i;
		}
	}
	FOR(i, pos+1, n) {
		if (a[i]!=a[i-1]-1)
			ok = false;
	}
	cout << 1 + ok << '\n';
}

ll get(int l, int r) {
	if (l<=0) return ps[r];
	return (ps[r]-ps[l-1]+MOD*MOD)%MOD;
}

void solve_2() {
	if (k==1) {cout << 0; return;}
	if (k==2) {cout << 1; return;}
	f[0] = ps[0] = 1;
	FOR(i, 1, n+1) {
		f[i] = get(i-k+1, i-1);
		ps[i] = (ps[i-1] + f[i])%MOD;
	}
	cout << f[n+1];
}

int main() {
	freopen("treelinek.inp", "r", stdin);
    freopen("treelinek.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	int h;
	cin >> n >> h >> k;
	FOR(i, 1, n) cin >> a[i];
	compress();
	if (!check()) {cout << 0 << '\n' << 0; return 0;}
	solve_1();
	solve_2();
	//cout << check()
}
