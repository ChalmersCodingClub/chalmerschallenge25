#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

void run() {
  int MAXN = Arg("maxn");
  int n = Int(1, MAXN);
  Endl();
  Int(1, 300000);
  Endl();
  int oats = 0;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    assert(str == "ADD" || str == "EAT" || str == "PASS");
    Endl();
    if (str == "ADD") {
      oats++;
    } else if (str == "EAT") {
      oats--;
    }
    assert(oats >= 0);
  }
  assert(oats == 0);
  Eof();
}

