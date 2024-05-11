#include <bits/stdc++.h>
#include "validator.h"


using namespace std;


void run() {
	int n = Int(1,Arg("maxn"));
	Endl();
	vector<int> nums = SpacedInts(n, 1, n+1);
	vector<int> seen(n);
	for (int i = 0; i < n; i++)
	{
		assert(seen[nums[i]-1]==0);
		seen[nums[i]-1]=1;
	}

	Eof();
}
