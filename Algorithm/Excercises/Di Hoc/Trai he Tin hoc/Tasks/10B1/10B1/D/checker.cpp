#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 128;
bool adj[maxN][maxN];
int ingroup[maxN];
int N, M;

void checkTree(const vector<int> &group) {
	vector<int> in(N, 0);
	int cnt = 0;
	int edges = 0;
	for (int u : group) for (int v : group) if (adj[u][v])
		edges++;
	if (edges/2 != group.size() - 1) {
		cerr << "Each group must be a tree" << endl;

		cout << "0.0" << endl;
		exit(0);
	}

	queue<int> q;
	q.push(group[0]);
	for (int u : group)
		in[u] = 1;
	in[group[0]] = 2;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		cnt++;
		for (int v = 0; v < N; v++) if (adj[u][v] && in[v] == 1) {
			in[v] = 2;
			q.push(v);
		}
	}
	if (cnt != group.size()) {
		cerr << "Each group must be a tree" << endl;
		cout << "0.0" << endl;
		exit(0);
	}
}

int main(int argc, char **argv) {
	ifstream input(argv[1]);
	ifstream output(argv[3]);

	input >> N >> M;
	while (M--) {
		int u, v;
		input >> u >> v;
		u--; v--;
		adj[u][v] = adj[v][u] = true;
	}

	int ngroups;
	output >> ngroups;

	if (ngroups <= 0 || ngroups > N) {
		cerr << "Invalid number of groups" << endl;
		cout << "0.0" << endl;
		return 0;
	}

	while (ngroups--) {
		int k;
		output >> k;
		if (k <= 0 || k > N) {
			cerr << "Invalid number of elements in group" << endl;
			cout << "0.0" << endl;
			return 0;
		}
		vector<int> group;
		while (k--) {
			int u;
			output >> u;
			u--;
			if (u < 0 || u >= N) {
				cerr << "Invalid node ID" << endl;
				cout << "0.0" << endl;
				return 0;
			}
			group.push_back(u);
		}
		for (int u : group)
			ingroup[u]++;
		checkTree(group);
	}
	for (int i = 0; i < N; i++) if (ingroup[i] != 1) {
		cerr << "Each element belongs to exactly one group" << endl;
		cout << "0.0" << endl;
		return 0;
	}
	cerr << "Output is correct" << endl;
	cout << "1.0" << endl;
	return 0;
}
