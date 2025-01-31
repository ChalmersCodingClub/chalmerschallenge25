#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "memento.h"

using namespace std;


namespace {
	static const int USER_FAIL = 120;
	const int num_testcases = 50;
	string _SECRET_KEY = "SUCCESSlmwnerhbiwerhuebifi";
	string _SECRET_FAIL = "FAILwerhiuwehruiwehuriphwer";
}


vector<pair<int,int>> generate_graph(mt19937& rng)
{
    vector<pair<int,int>> ret;
    uniform_int_distribution<int> m_dist(3500, 4500);
	uniform_int_distribution<int> node_dist(0, 999);
    int m = m_dist(rng);

    set<pair<int,int>> seen;
    for (int i = 0; i < m; i++)
    {
        while (true)
        {
            int a = node_dist(rng);
            int b = node_dist(rng);
            if (a==b) continue;
            if (seen.find(pair<int,int>(a,b))!=seen.end()) continue;
            seen.insert(pair<int,int>(a,b));
            seen.insert(pair<int,int>(b,a));
            ret.emplace_back(a,b);
            break;
        }
    }
    return ret;
}

vector<pair<int,int>> shuffle_graph(vector<pair<int,int>> graph, mt19937& rng)
{
    vector<int> permute(1000);
    for (int i = 0; i < 1000; i++) permute[i] = i;
    shuffle(permute.begin(), permute.end(), rng);
    shuffle(graph.begin(), graph.end(), rng);
    uniform_int_distribution<int> bool_dist(0, 1);
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i].first = permute[graph[i].first];
        graph[i].second = permute[graph[i].second];
        if (bool_dist(rng)) swap(graph[i].first, graph[i].second); 
    }
    return graph;
}

int main() {
	ios_base::sync_with_stdio(false);

	int seed;
	cin >> seed;
	mt19937 rng(seed);

	int pipefds[2];
	ignore = pipe(pipefds);

	vector<pair<int,int>> edges = generate_graph(rng);

	pid_t pid = fork();
	if (pid == 0) {
		close(pipefds[0]);

		vector<pair<int,int>> res = run(edges);

		if (res.size() != 30)
		{
			cout << _SECRET_FAIL << "Did not give 30 edges in first round" << endl;
			close(pipefds[1]);
			exit(USER_FAIL);
		}

		for (int i = 0; i < 30; i++)
		{
			int a,b;
			tie(a,b) = res[i];
			if (a<0||b<0||a>=1000||b>=1000 || a==b)
			{
				cout << _SECRET_FAIL << "Gave invalid edge in first round" << endl;
				close(pipefds[1]);
				exit(USER_FAIL);
			}
		}

		char nullbyte[1];
		nullbyte[0]=0;
		char dollar[1];
		dollar[0]='$';
		for (auto e : res)
		{
			string a = to_string(e.first);
			string b = to_string(e.second);
			ignore = write(pipefds[1], a.c_str(), a.size());
			ignore = write(pipefds[1], dollar, 1);
			ignore = write(pipefds[1], b.c_str(), b.size());
			ignore = write(pipefds[1], dollar, 1);
		}
		
		ignore = write(pipefds[1], nullbyte, 1);
		
		close(pipefds[1]);
		exit(EXIT_SUCCESS);
	}
	else {
		int status;
		char buf[50000];
		if (waitpid(pid, &status, 0) == -1) {
			perror("waitpid fail");
			return EXIT_FAILURE;
		}
		if (WIFSIGNALED(status)) {
			kill(getpid(), WTERMSIG(status));
			exit(1);
		}
		int ex = WEXITSTATUS(status);
		if (ex == USER_FAIL) { exit(0); }
		if (ex != EXIT_SUCCESS) { exit(ex); }
		ignore = read(pipefds[0], buf, sizeof(buf));
		
		string curr_string = "";
		bool s_curr = 1;
		for (int i = 0; i < 50000; i++)
		{
			if (buf[i] == 0) break;
			if (buf[i]=='$')
			{
				if (s_curr)
				{
					edges.emplace_back(-1,-1);
					edges.back().first = stoi(curr_string);
				}
				else edges.back().second = stoi(curr_string);
				s_curr ^= 1;
				curr_string = "";
			}
			else
			{
				curr_string += buf[i];
			}
		}
		shuffle_graph(edges, rng);

		vector<pair<int,int>> res = run(edges);
		if (res.size() > 0)
		{
			cout << _SECRET_FAIL << "Did not recognize it had already seen graph in second round" << endl;
			close(pipefds[1]);
			exit(0);
		}

		cout << _SECRET_KEY << seed << endl;
		exit(EXIT_SUCCESS);
	}

}
