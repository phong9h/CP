#include <bits/stdc++.h>
using namespace std;

#define maxn 1000002
#define FOR(i, l, r) for (int i=l; i<=r; ++i)
#define FORD(i, r, l) for (int i=r; i>=l; --i)
#define fi first
#define se second
#define sz size
typedef long long ll;
const int inf = 1e9;
const string name = "birthday";
const int nTests = 1;

int a[maxn];

void Generate() {
    ofstream inp((name + ".inp").c_str());
   	int n = 1000000;
	inp << n << '\n';
	FOR(i, 1, n) a[i] = i;
	random_shuffle(a+1, a+n+1);
	FOR(i, 1, n) inp << a[i] << ' ';
   	inp.close();
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(0); cin.tie(0);
    FOR(i, 1, nTests) {
        Generate();
        /*system(("./" + name).c_str());
        system(("./" + name + "_trau").c_str());
        if (system(("diff " + name + ".ans " + name + ".out").c_str())!=0) {
			cerr << "Found!\n";
            return 0;
		}
		cerr << "Test " << i << ": Correct!\n";*/
    }
}

