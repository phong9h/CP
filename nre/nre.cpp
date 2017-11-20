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

#define maxn 200002
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

int n, m, b[maxn], ps[maxn], f[maxn];
map<ii, int> bit;
vector<int> a[maxn];

void update(int l, int r, int val) {
	for (int tmp_l=l; tmp_l<=n; tmp_l += tmp_l&(-tmp_l)) {
		for (int tmp_r=r; tmp_r<=n; tmp_r += tmp_r&(-tmp_r)) {
			if (bit.find(ii(tmp_l, tmp_r))==bit.end())
				bit[ii(tmp_l, tmp_r)] = val;
			else bit[ii(tmp_l, tmp_r)] = min(bit[ii(tmp_l, tmp_r)], val);
		}
	}
}

int get(int l, int r) {
	int res = inf;
	for (int tmp_l=l; tmp_l>0; tmp_l -= tmp_l&(-tmp_l)) {
		for (int tmp_r=r; tmp_r>0; tmp_r -= tmp_r&(-tmp_r)) {
			if (bit.find(ii(tmp_l, tmp_r))!=bit.end())
				res = min(res, bit[ii(tmp_l, tmp_r)]);
		}
	}
	return res;
}

int main() {
    //freopen("nre.inp", "r", stdin);
    //freopen("nre.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	FOR(i, 1, n) {
		cin >> b[i];
		ps[i] = ps[i-1] + (b[i]==0);
	}
	cin >> m;
	FOR(i, 1, m) {
		int u, v; cin >> u >> v;
		a[v].push_back(u);
	}
	FOR(r, 1, n) {
		f[r] = f[r-1] + (b[r]!=0);
		REP(j, a[r].sz()) {
			int l = a[r][j];
			int tmp = min(f[l-1]-ps[l-1], get(l, n+1-l));
			f[r] = min(f[r], tmp+ps[r]);
			update(l, n+1-r, tmp);
		}
	}
	cout << f[n];
}
