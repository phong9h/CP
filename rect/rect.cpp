#include <bits/stdc++.h>
#include "creclib.h"

typedef double db;

int main() {
	while (true) {
		int m = dimension_x(), n = dimension_y();
		if (m>n) {
			int t = log(db(m+1)/db(n+1))/log(2.0);
			cut(vertical, m - (1<<t)*n - (1<<t) + 1);
		}
		else {
			int t = log(db(n+1)/db(m+1))/log(2.0);
			cut(horizontal, n - (1<<t)*m - (1<<t) + 1);
		}
	}
}
