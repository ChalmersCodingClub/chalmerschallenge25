#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

void run() {
  Int(1, 3);
  Endl();
  int n = Int(1, 100);
  Endl();
  for (int i = 0; i < n; i++) {
    int a, b;
    a = Int(1, 3);
    Space();
    b = Int(1, 3);
    Endl();
    assert(a < b);
  }
  Eof();
}

