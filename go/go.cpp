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

stack<ii> st;

int read_int() {
	int res = 0;
	bool start = false;
	char r;
	while (true) {
		r = getchar();
		if ((r<'0' || r>'9') && !start)
			continue;
		if ((r<'0' || r>'9') && start)
			break;
		if (start) res *= 10;
		start = true;
		res += r-'0';
	}
	return res;
}

int main() {
    freopen("go.inp", "r", stdin);
    freopen("go.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	int T; T = read_int();
	while (T--) {
		int n; n = read_int();
		FOR(i, 1, n) {
			int x; x = read_int();
			if (st.empty()) {st.push(ii(x, 1)); continue;}
			if (i%2) {
				if (x==st.top().fi) st.top().se++;
				else st.push(ii(x, 1));
			}	
			else {
				if (x==st.top().fi) st.top().se++;
				else {
					int tmp = 0;
					REP(j, 2) {
						if (st.sz()) {tmp += st.top().se; st.pop();}
					}
					st.push(ii(x, tmp+1));
				}
			}
			//if (i==4) {
			//	while (st.sz()) {DB(st.top().fi); DB(st.top().se); st.pop();}
			//}
		}
		int res = 0;
		while (st.sz()) {
			if (st.top().fi==0) res += st.top().se;
			st.pop();
		}
		cout << res << '\n';
	}
}
