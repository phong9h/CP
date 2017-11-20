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
const ll MOD = 1000000007;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

string s1, s2, p, str_tmp;
ll H[maxn], POW2[maxn], f[maxn];
int n, tmp1, tmp2, st;

ll get(int l, int r) {
	if (l==0) return H[r];
	return (H[r] - POW2[r-l+1]*H[l-1] + MOD*MOD)%MOD;
}

int calc(string s) {
	REP(i, s.sz()) {
		H[i] = (H[i-1]*2 + s[i]-'0')%MOD;
	}
	POW2[0] = 1;
	FOR(i, 1, (int)s.sz()) POW2[i] = POW2[i-1]*2%MOD;
	ll tmp = 0;
	REP(i, p.sz()) tmp = tmp*2 + p[i]-'0';
	int tot = 0;
	REP(i, s.sz()) {
		if (i+p.sz()-1<(int)s.sz() && get(i, i+p.sz()-1)==tmp)
			++tot;
	}
	return tot;
}

ll calc(int n) {
	if (f[n]>-1) return f[n];
	if (n==st+1) return calc(s2+s1);
	if (n==st) return calc(s2);
	if ((n-st)%2==0) return f[n] = calc(n-1) + calc(n-2) + tmp1;
	return f[n] = calc(n-1) + calc(n-2) + tmp2;
}

ll solve() {
	cin >> p;
	int cnt = 0;
	s1 = "0";
	s2 = "1";
	st = 2;
	while (s1.sz()<p.sz() || s2.sz()<p.sz()) {
		++st;
		str_tmp = s2;
		s2 += s1;
		s1 = str_tmp;
	}
	memset(f, -1, sizeof(f));
	if (n<st-1) return 0;
	if (n==st-1) return calc(s1);
	tmp1 = calc(s1+s2) - calc(s1) - calc(s2); tmp2 = calc(s2+s2) - calc(s2)*2;
	//FOR(i, 4, 6) DB(calc(i));
	return calc(n+1);
}

int main() {
    //freopen("fibwords.inp", "r", stdin);
    //freopen("fibwords.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	int cnt = 0;
	p = "11";
	s2 = "101";
	//DB(calc(s2));
	while (cin >> n) {
		cout << "Case " << ++cnt << ": ";
		cout << solve() << '\n';
	}
}
