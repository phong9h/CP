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

int n, k, len, a[maxn], p;
bool ok = true;
stack<int> st, tmp;

void init() {
	while (st.sz()) st.pop();
	FOR(i, 1, n-len) {
		while (st.sz() && st.top()<a[i]) {
			if (st.top()!=p+1) {
				ok = false;
				return;
			}
			p = st.top(); st.pop();
		}
		st.push(a[i]);
	}
}

bool check_2() {
	if (st.sz()>len+1 || !ok) return false;
	tmp = st;
	int prev = p;
	FOR(i, n-len+1, n) {
		while (tmp.sz() && tmp.top()<a[i]) {
			if (tmp.top()!=prev+1) return false;
			prev = tmp.top(); tmp.pop();
		}
		tmp.push(a[i]);
	}
	while (tmp.sz()) {
		if (tmp.top()!=prev+1) return false;
		prev = tmp.top(); tmp.pop();
	}
	return true;
}

int main() {
	//freopen("ssort.inp", "r", stdin);
    //freopen("ssort.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	int tot = 0;
	len = min(10, n);
	init();
	FOR(i, 1, k) {
		tot += check_2();
		next_permutation(a+n-len+1, a+n+1);
	}
	cout << tot;
}




