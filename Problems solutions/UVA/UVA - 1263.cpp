#include<bits/stdc++.h>
using namespace std;
#define Ma7moud_7amdy ios_base::sync_with_stdio(false);  cin.tie(NULL);cout.tie(NULL);
#define Open_Sesame Open()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define watch(x) cout << #x << " = " << x << endl;
#define endl "\n"
typedef long long ll;
void Open() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 2000 + 5;
//"The secret of getting ahead is getting started". Mark Twain
int n, curdfsNum = 0, ans = 0;
vector<vector<int>> adj, comps, graph;
int inStack[N], lowLink[N], dfsNum[N], comp[N];
stack<int> st;
void tarjan(int node) {
	lowLink[node] = dfsNum[node] = ++curdfsNum;

	inStack[node] = 1, st.push(node);

	for (auto child : adj[node]) {
		if (!dfsNum[child]) {
			tarjan(child);
			lowLink[node] = min(lowLink[node], lowLink[child]);
		} else if (inStack[child])
			lowLink[node] = min(lowLink[node], dfsNum[child]);
	}
	if (lowLink[node] == dfsNum[node]) {
		comps.push_back(vector<int>());
		graph.push_back(vector<int>());
		int x = -1, curComp = (int) comps.size() - 1;
		while (x != node) {
			x = st.top(), st.pop(), inStack[x] = 0;

			comps.back().push_back(x);
			comp[x] = curComp;

		}
	}
}
void getLeaves(int i) {
	if (inStack[i])
		return;
	inStack[i] = 1;
	if (graph[i].empty())
		ans++;
	else
		for (int nxt : graph[i])
			getLeaves(nxt);
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int t, id = 0;
	cin >> t;
	while (t--) {
		curdfsNum = 0;
		memset(lowLink, 0, sizeof lowLink);
		memset(dfsNum, 0, sizeof dfsNum);
		memset(inStack, 0, sizeof inStack);
		memset(comp, 0, sizeof comp);
		comps.clear();
		st = stack<int>();

		cin >> n;
		adj = vector<vector<int>>(n + 1), comps.clear();
		graph = vector<vector<int>>();
		vector<ll> X(n), Y(n), D(n);
		for (int i = 0; i < n; i++) {
			cin >> X[i] >> Y[i] >> D[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && abs(X[i] - X[j]) <= D[i] / 2
						&& abs(Y[i] - Y[j]) <= D[i] / 2)
					adj[i].push_back(j);
			}
		}

		for (int i = 0; i < n; i++) {
			if (!dfsNum[i])
				tarjan(i);
		}
		for (int i = 0; i < n; i++) {
			for (int j : adj[i]) {
				if (comp[i] != comp[j])
					graph[comp[j]].push_back(comp[i]);
			}
		}

		memset(inStack, 0, sizeof inStack);
		ans = 0;
		for (int i = 0; i <(int) graph.size(); i++)
			if (!inStack[i])
				getLeaves(i);
		cout <<  ans << endl;

	}
}
//"There's a way to do it better - find it". Thomas A. Edison
