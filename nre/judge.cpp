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
const string name = "nre";
const int nTests = 1000;

void Generate() {
    ofstream inp((name + ".inp").c_str());
   	int n = rand()%5+1, m = rand()%3+1;
	inp << n << ' ';
	FOR(i, 1, n) inp << rand()%2 << ' ';
	inp << '\n';
	inp << m << '\n';
	FOR(i, 1, m) {
		int l = rand()%n+1, r = l + rand()%(n-l+1);
		inp << l << ' ' << r << '\n';
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

