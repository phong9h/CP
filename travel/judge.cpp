#include <bits/stdc++.h>
using namespace std;

#define maxn
#define FOR(i, l, r) for (int i=l; i<=r; ++i)
#define FORD(i, r, l) for (int i=r; i>=l; --i)
#define REP(i, r) for (int i=0; i<(int)r; ++i)
#define fi first
#define se second
#define sz size
typedef long long ll;
const int inf = 1e9;
const string name = "travel";
const int nTests = 100;


void Generate() {
    ofstream inp((name + ".inp").c_str());
	int n = 50000, m = 2*n;
	inp << n << ' ' << m << '\n';
	FOR(i, 1, n-1) {
		int p = rand()%i;
		inp << p+1 << ' ' << i+1 << '\n';
	}
	FOR(i, 1, m-n+1) {
		int x = rand()%n, y = x + 1 + rand()%(n-x);
		if (x==0) {x = 1; y = n;}
		inp << x << ' ' << y << '\n';
	}	
   	inp.close();
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(0); cin.tie(0);
    FOR(i, 1, nTests) {
        Generate();
        system(("./" + name).c_str());
        /*system((name + "_trau.exe").c_str());
        if (system(("fc " + name + ".ans " + name + ".out").c_str())!=0)
            return 0;*/
		cerr << "Test " << i << ": \n";
    }
}

