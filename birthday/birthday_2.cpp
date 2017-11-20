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

#define maxn 1000002
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

int n, a[maxn];
vector<ii> p;

bool check_1(int v) {
	p.clear();
	REP(i, n) {
		int l = (i-v-a[i]+1+2*n)%n, r = (i+v-a[i]+1+n)%n;
		if (l<r) {
			p.push_back(ii(l, 1)); 
			p.push_back(ii(r, -1));
		}
		else {
			p.push_back(ii(l, 1)); 
			p.push_back(ii(n, -1));
			p.push_back(ii(0, 1));
			p.push_back(ii(r+1, -1));
		}
	 }
	 sort(p.begin(), p.end());
	 int cnt = 0;
	 REP(i, p.sz()) {
		cnt += p[i].se;
		if (cnt==n) return true;
	 }
	 return false;
}

bool check_2(int v) {
	p.clear();
	REP(i, n) {
		int l = (i-v+a[i]-1+2*n)%n, r = (i+v+a[i]-1+n)%n;
		if (l<r) {
			p.push_back(ii(l, 1)); 
			p.push_back(ii(r, -1));
		}
		else {
			p.push_back(ii(l, 1)); 
			p.push_back(ii(n, -1));
			p.push_back(ii(0, 1));
			p.push_back(ii(r+1, -1));
		}
	 }
	 sort(p.begin(), p.end());
	 int cnt = 0;
	 REP(i, p.sz()) {
		cnt += p[i].se;
		if (cnt==n) return true;
	 }
	 return false;
}

void bisect() {
	int l=1, r=n-1, mid = (l+r)/2;
	while (l!=mid && mid!=r) {
		if (check_1(mid) || check_2(mid)) r = mid;
		else l = mid;
		mid = (l+r)/2;
	}
	FOR(i, l, r) {
		if (check_1(i) || check_2(i)) {
			cout << i;
			return;
		}
	}
}

int main() {
    freopen("birthday.inp", "r", stdin);
    //freopen("", "w", stdout);
	scanf("%d", &n);
	REP(i, n) {scanf("%d", &a[i]); --a[i];}
	//DB(check(3));
	bisect();
}
