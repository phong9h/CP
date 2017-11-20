#include <bits/stdc++.h>
using namespace std;

#define maxn
#define FOR(i, l, r) for (int i=l; i<=r; ++i)
#define FORD(i, r, l) for (int i=r; i>=l; --i)
#define fi first
#define se second
#define sz size
typedef long long ll;
const int inf = 1e9;
const string name = "voland";
const int nTests = 100;

void Generate() {
    ofstream inp((name + ".inp").c_str());
	int m = rand()%5+1, n = rand()%5+1, a = rand()%3+1, b = rand()%3+1, k = rand()%2+1;
 	inp << m << ' ' << n << ' ' << a << ' ' << b << ' ' << k << '\n';
	FOR(i, 1, m) {
		FOR(j, 1, n) inp << -5 + rand()%10 << ' ';
		inp << '\n';
	}	
   	inp.close();
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(0); cin.tie(0);
    FOR(i, 1, nTests) {
        Generate();
        system(("./" + name).c_str());
        system(("./" + name + "_trau").c_str());
        if (system(("diff " + name + ".ans " + name + ".out").c_str())!=0) {
			cerr << "Found!\n";
            return 0;
		}
		cerr << "Test " << i << ": Correct!\n";
    }
}

