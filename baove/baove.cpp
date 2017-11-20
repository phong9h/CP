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

#define maxn 5002
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

int n, m, c[maxn][maxn], f[maxn][maxn], q, d[maxn], visited[maxn];
vector<int> a[maxn];
queue<int> qu;

bool findPath() {
	memset(d, -1, sizeof(d));
	d[n] = 0;
	qu.push(n);
	while (qu.sz()) {
		int u = qu.front(); qu.pop();
		REP(i, a[u].sz()) {
			int v = a[u][i];
			if (c[u][v]>f[u][v] && d[v]==-1) {
				d[v] = d[u] + 1;
				qu.push(v);
			}
		}
	}
	return d[1]>-1;
}

int incFlow(int u, int MIN) {
	if (u==1) return MIN;
	if (visited[u]!=q) visited[u] = q;
	else return 0;
	REP(i, a[u].sz()) {
		int v = a[u][i];
		if (c[u][v]>f[u][v] && d[v]==d[u]+1) {
			int x = incFlow(v, min(MIN, c[u][v]-f[u][v]));
			if (x==0) continue;
			f[u][v] += x;
			f[v][u] -= x;
			return x;
		} 
	}
	return 0;
}

int main() {
    //freopen("baove.inp", "r", stdin);
    //freopen("", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int u, v, w;
	while (cin >> u >> v >> w) {
		a[u].push_back(v);
		a[v].push_back(u);
		c[u][v] += w;
	}
	int minCut = 0;
	while (findPath()) {
		while (true) {
			++q;
			int x = incFlow(n, inf);
			minCut += x;
			if (x==0) break;
		}
	}
	cout << minCut;
}
