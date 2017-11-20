#include <bits/stdc++.h>
using namespace std;
#define N 2006
#define st first
#define nd second
typedef long long ll;
typedef pair<ll,ll> ii;
const ll oo = 1e18;
int n, m, x, y, k;
ll a[N][N], b[N][N];
ll f[N][N], hcn[N][N], thoi[N][N];
ll up[N], dow[N], lef[N], righ[N];
ll len[N], xuong[N], trai[N], phai[N];
ll res = -oo;
void init();
void init2();
 
void xly1()
{
    int i = 0;
    while ( ++i <= n - x - 2 * k )
        res = max ( res, up[i] + xuong[i+x+k] );
    i = k;
    while ( ++i <= n - x - k )
        res = max ( res, len[i] + dow[i+k+1] );
 
    int j = 0;
    while ( ++j <= m - y - 2 * k )
        res = max ( res, lef[j] + phai[j+y+k] );
    j = k;
    while ( ++j <= m - y - k )
        res = max ( res, trai[j] + righ[j+k+1] );
}
 
int main()
{
   	freopen("voland.inp","r",stdin);
    //freopen("voland.ans","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y >> k;
    for ( int i = 1; i <= n; i++)
        for ( int j = 1; j <= m; j++) cin >> a[i][j];
    init();
    init2();
    xly1();
    if ( res == -oo ) cout << "no solution";
    else cout << res;
}
void init()
{
    for ( int i = 1; i <= n; i++)
        for ( int j = 1; j <= m; j++)
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
    for ( int i = 1; i <= n - x + 1; i++)
    for ( int j = 1; j <= m - y + 1; j++) {
        int u = i + x - 1;
        int v = j + y - 1;
        hcn[i][j] = f[u][v] - f[i-1][v] - f[u][j-1] + f[i-1][j-1];
    }
    int mn = max ( m, n );
    for ( int i = 1; i <= mn; i++)
        for ( int j = 1; j <= mn; j++) b[i+j-1][mn-i+j] = a[i][j];
 
    memset(f,0,sizeof(f) );
    for (int i = 1; i < mn + mn; i++)
        for ( int j = 1; j < mn + mn; j++)
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + b[i][j];
 
    for ( int i = 1 + k; i <= n - k; i++)
    for ( int j = 1 + k; j <= m - k; j++) {
        ii u, v;
        u = ii ( i, j - k );
        v = ii ( i, j + k );
        u = ii ( u.st + u.nd - 1, mn - u.st + u.nd );
        v = ii ( v.st + v.nd - 1, mn - v.st + v.nd );
        thoi[i][j] = f[v.st][v.nd] - f[u.st-1][v.nd] - f[v.st][u.nd-1] + f[u.st-1][u.nd-1];
    }
}
void init2()
{
    memset(up,0,sizeof(up));
    memset(dow,0,sizeof(dow));
    memset(lef,0,sizeof(lef));
    memset(righ,0,sizeof(righ));
    memset(len,0,sizeof(len));
    memset(xuong,0,sizeof(xuong));
    memset(trai,0,sizeof(trai));
    memset(phai,0,sizeof(phai));
    for ( int i = 1; i <= n - x + 1; i++) {
        up[i] = up[i-1];
        for ( int j = 1; j <= m - y + 1; j++)
            up[i] = max ( up[i], hcn[i][j] );
    }
    for ( int i = n - x + 1; i >= 1; i-- ) {
        dow[i] = dow[i+1];
        for ( int j = 1; j <= m - y + 1; j++)
            dow[i] = max ( dow[i], hcn[i][j] );
    }
    for ( int j = 1; j <= m - y + 1; j++) {
        lef[j] = lef[j-1];
        for ( int i = 1 ;i <= n - x + 1; i++)
            lef[j] = max ( lef[j], hcn[i][j] );
    }
    for ( int j = m - y + 1; j >= 1; j--) {
        righ[j] = righ[j+1];
        for ( int i = 1; i <= n - x + 1; i++)
            righ[j] = max ( righ[j], hcn[i][j] );
    }
 
    for ( int i = 1 + k; i <= n - k; i++) {
        len[i] = len[i-1];
        for ( int j = 1 + k; j <= m - k; j++)
            len[i] = max ( len[i], thoi[i][j] );
    }
    for ( int i = n - k; i >= 1 + k; i-- ) {
        xuong[i] = xuong[i+1];
        for ( int j = 1 + k; j <= m - k; j++)
            xuong[i] = max ( xuong[i], thoi[i][j] );
    }
    for ( int j = 1 + k; j <= m - k; j++) {
        trai[j] = trai[j-1];
        for ( int i = 1 + k; i <= n - k; i++)
            trai[j] = max ( trai[j], thoi[i][j] );
    }
    for ( int j = m - k; j >= 1 + k; j-- ) {
        phai[j] = phai[j+1];
        for ( int i = 1 + k; i <= n - k; i++)
            phai[j] = max ( phai[j], thoi[i][j] );
    }
}
