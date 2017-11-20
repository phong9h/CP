#include <bits/stdc++.h>
using namespace std;

#define maxn 402
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
#define sz size
#define Debug(X) {cerr << #X << " = " << X << '\n';}
#define PR(A, n) {cerr << #A << " = "; FOR(i, 1, n) cerr << A[i] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i] << ' '; cerr << '\n';}
typedef long long ll;
typedef double db;
typedef pair<db, db> dd;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 1e9;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

struct element {
    int val, x, y;
    element() {}
    element(int v, int i, int j) {
        val = v; x = i; y = j;
    }
} b[maxn*maxn];

int m, n, L[maxn][maxn][maxn], appeared[maxn*maxn];
int a[maxn][maxn], p[maxn][maxn][maxn];
vector<int> pos[maxn*maxn];

bool cmp(element a, element b) {
    return a.val<b.val;
}

void compress() {
    int cnt = 0, tmp = 0;
    FOR(i, 1, m) FOR(j, 1, n)
        b[++tmp] = element(a[i][j], i, j);
    sort(b+1, b+tmp+1, cmp);
    FOR(i, 1, tmp) {
        if (b[i].val!=b[i-1].val) ++cnt;
        a[b[i].x][b[i].y] = cnt;
    }
}

void init() {
    int t = 0;
    FOR(i, 1, m) FOR(j, 1, n-1) {
        FOR(k, 1, j) pos[a[i][k]].clear();
        FOR(k, 1, m) pos[a[k][j+1]].push_back(k);
        ++t;
        FORD(k, j, 1) {
            if (appeared[a[i][k]]==t) continue;
            appeared[a[i][k]] = t;
            REP(q, pos[a[i][k]].sz())
                L[pos[a[i][k]][q]][j+1][i] = k;
        }
    }
}

bool check(int u, int d, int l, int r) {
    if (r<l) return true;
    return p[u][d-1][r]<=l && p[u+1][d][r]<=l && p[u][d][r-1]<=l
            && L[u][r][u]+1<=l && L[d][r][d]+1<=l && L[u][r][d]+1<=l
            && L[d][r][u]+1<=l && (a[u][r]!=a[d][r] || u==d);
}

int main() {
    freopen("board.inp", "r", stdin);
    freopen("board.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    compress();
    init();
    int res = 0;
    FOR(len, 1, m)
    FOR(i, 1, m) {
        if (i+len-1>m) break;
        int l = 1;
        FOR(r, 1, n) {
            while (!check(i, i+len-1, l, r))
                ++l;
            p[i][i+len-1][r] = l;
            res = max(res, len*(r-l+1));
        }
    }
    cout << res;
}


