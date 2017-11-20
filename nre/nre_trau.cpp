# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# define A first
# define B second
# define lson l, m, id<<1
# define rson m+1, r, id<<1|1
using namespace std;
const int maxn = 2e5+30;
const int oo = 0x3f3f3f3f;
int imin[maxn<<2], cost[maxn], dp[maxn];
void build(int l, int r, int id)
{
    if(l == r)
    {
        imin[id] = oo;
        return;
    }
    int m = l+r>>1;
    build(lson);
    build(rson);
    imin[id] = min(imin[id<<1], imin[id<<1|1]);
}
 
int query(int L, int R, int l, int r, int id)
{
    if(L<=l && r<=R) return imin[id];
    int m = l+r>>1, res = oo;
    if(L <= m) res = min(res, query(L, R, lson));
    if(R > m) res = min(res, query(L, R, rson));
    return res;
}
 
void update(int pos, int val, int l, int r, int id)
{
    if(l == r)
    {
        imin[id] = min(imin[id], val);
        return;
    }
    int m = l+r>>1;
    if(pos <= m) update(pos, val, lson);
    else update(pos, val, rson);
    imin[id] = min(imin[id<<1], imin[id<<1|1]);
}
vector<int>v[maxn];
int main()
{
	freopen("nre.inp", "r", stdin);
	freopen("nre.ans", "w", stdout);
    int n, q, cnt=0;
    scanf("%d",&n);
    build(1, n, 1);
    for(int i=1, j; i<=n; ++i)
    {
        scanf("%d",&j);
        cnt += !j;
        cost[i] = j?1:-1;
    }
    scanf("%d",&q);
    for(int i=0, j, k; i<q; ++i)
    {
        scanf("%d%d",&j,&k);
        v[j].push_back(k);
    }
    memset(dp, oo, sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<=n; ++i)
    {
        for(auto j : v[i])
        {
            int mi = dp[i-1];
            mi = min(mi, query(max(i-1,1), j, 1, n, 1));
            if(mi < dp[j])//chose
            {
                dp[j] = mi;
                update(j, mi, 1, n, 1);
            }
        }
        dp[i] = min(dp[i], dp[i-1]+cost[i]); //not chose
    }
    printf("%d",dp[n]+cnt);
    return 0;
}
