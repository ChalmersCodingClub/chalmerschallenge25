#include <bits/stdc++.h>
#include "validator.h"


using namespace std;

void run() {
	int MAXN = Arg("maxn");
	int MAXH = Arg("maxh");
	int MINX = Arg("minx");
	int MAXX = Arg("maxx");

	int n = Int(1, MAXN);
	Endl();
	
	int h = Int(0, MAXH);
	Endl();
	for (int i = 0; i < n; i++)
	{
		int x = Int(MINX, MAXX);
		Space();
		int y = Int(0, MAXH);
		Endl();
	}

	Eof();
}
