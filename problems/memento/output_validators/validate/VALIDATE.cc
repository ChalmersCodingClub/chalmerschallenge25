#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }

int main(int argc, char **argv) {
    init_io(argc, argv);

    string _SECRET_FAIL = "FAILwerhiuwehruiwehuriphwer";

    string line;
    getline(author_out, line);

    string ans;
    judge_ans >> ans;

    if (line == ans)
    {
        accept();
    }
    else if (line.find(_SECRET_FAIL)==0)
    {
        line = line.substr(_SECRET_FAIL.size());
        author_message(line.c_str());
        wrong_answer(line.c_str());
    }
    else
    {
        author_message("Unexpected output. Did you write to stdout?");
        wrong_answer("Unexpected output");
    }

    return 0;
}
