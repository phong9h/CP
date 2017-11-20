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
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

int n, cnt=1, tmp, L, R;

struct lz {
	int L, val, atL;
	lz() {}
	lz(int a, int b, int c) {
		L = a; val = b; atL = c;
	}	
};

struct node {
	int l, r;
	int LChild, RChild;
	int MAX, lazy2;
	lz lazy;
	node() {MAX = LChild = RChild = 0;}
} st[maxn*4];

void init(int id) {
	if (st[id].LChild==0) st[id].LChild = ++cnt;
	if (st[id].RChild==0) st[id].RChild = ++cnt;
	int mid = (st[id].l+st[id].r)/2;
	st[st[id].LChild].l = st[id].l; st[st[id].LChild].r = mid;
	st[st[id].RChild].l = mid+1, st[st[id].RChild].r = st[id].r;
}

void down(int id) {
	lz tmp = st[id].lazy; st[id].lazy.L = -1;
	int tmp2 = st[id].lazy2; st[id].lazy2 = 0; 
	int LChild = st[id].LChild, RChild = st[id].RChild;
	st[LChild].MAX += tmp2;
	st[RChild].MAX += tmp2;
	st[LChild].lazy2 += tmp2;
	st[RChild].lazy2 += tmp2;
	if (tmp.L==-1) return;
	st[LChild].lazy = tmp;
	st[RChild].lazy = tmp;
	if (tmp.val<0) {
		st[LChild].MAX = tmp.atL + (st[LChild].r-tmp.L+1)*tmp.val;
		st[RChild].MAX = tmp.atL + (st[RChild].r-tmp.L+1)*tmp.val;
	}
	else {
		st[LChild].MAX = tmp.atL + (st[LChild].r-tmp.L+1)*tmp.val;
		st[RChild].MAX = tmp.atL + (st[RChild].r-tmp.L+1)*tmp.val;
	}
}

int get(int u, int v, int id) {
	init(id);
	if (v<st[id].l || u>st[id].r) return 0;
	if (u<=st[id].l && st[id].r<=v) return st[id].MAX;
	down(id);
	return max(get(u, v, st[id].LChild), get(u, v, st[id].RChild));
}

void update(int u, int v, int val, int id) {
	init(id);
	if (v<st[id].l || u>st[id].r) return;
	if (u<=st[id].l && st[id].r<=v) {
		if (val<0) st[id].MAX = tmp + val;
		else st[id].MAX = tmp + 1LL*(st[id].r-L+1)*val;	
		st[id].lazy = lz(L, val, tmp);
		return;
	}
	down(id);
	update(u, v, val, st[id].LChild);
	update(u, v, val, st[id].RChild);
	st[id].MAX = max(st[st[id].LChild].MAX, st[st[id].RChild].MAX);
}

void update_1(int u, int v, int val, int id) {
	init(id);
	if (v<st[id].l || u>st[id].r) return;
	if (u<=st[id].l && st[id].r<=v) {
		st[id].MAX += val;
		st[id].lazy2 += val;
		return;
	}
	down(id);
	update_1(u, v, val, st[id].LChild);
	update_1(u, v, val, st[id].RChild);
}

int solve(int h, int id) {
	init(id);
	if (st[id].l>st[id].r) return n+1;
	if (st[id].l==st[id].r) return st[id].MAX>h ? st[id].l : n+1;
	int LChild = st[id].LChild, RChild = st[id].RChild;
	int tmp = solve(h, LChild);
	if (tmp<=st[LChild].r) return tmp;
	return solve(h, RChild);
}

int main() {
    freopen("mountains.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	st[1].l = 1; st[1].r = n;
	while (true) {
		char opt; cin >> opt;
		if (opt=='E') break;
		if (opt=='I') {
			int w;
			cin >> L >> R >> w;
			tmp = get(L-1, R-1, 1);
			update(L, R, w, 1);
			update_1(R+1, n, get(R, R, 1), 1);
		}
		if (opt=='Q') {
			int h; cin >> h;
			cout << solve(h, 1)-1 << '\n';
		}
	}
}
