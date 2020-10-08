#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define Ma7moud_7amdy ios_base::sync_with_stdio(false);  cin.tie(NULL);cout.tie(NULL);
#define Open_Sesame Open()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define watch(x) cout << #x << " = " << x << endl;
#define endl "\n"
typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
void Open() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 1e5 + 5;
//"The secret of getting ahead is getting started". Mark Twain
int n, m, curdfsNum = 0, cnt;
vector<vector<int>> adj, compGraph, comps;
int inStack[N], lowLink[N], dfsNum[N], comp[N];
stack<int> st;

void tarjan(int node) {
	lowLink[node] = dfsNum[node] = ++curdfsNum;
	st.push(node), inStack[node] = 1;

	for (auto child : adj[node]) {
		if (!dfsNum[child]) {
			tarjan(child);
			lowLink[node] = min(lowLink[node], lowLink[child]);
		}
		else if (inStack[child])
			lowLink[node] = min(lowLink[node], dfsNum[child]);
	}
	if (lowLink[node] == dfsNum[node]) {

		comps.push_back(vector<int>());
		int x = -1;
		cnt++;
		while (x != node) {
			x = st.top(), st.pop(), inStack[x] = 0;
			comp[x] = cnt - 1;
			comps.back().push_back(x + 1);
		}
	}
}
bitset<N>bt;
void dfs(int node) {
	if (inStack[node])return;
	if (compGraph[node].empty())bt[node] = 1;
	inStack[node] = 1;
	for (int child : compGraph[node])dfs(child);
}
int main() {
	Ma7moud_7amdy;
	Open_Sesame;
	cin >> n >> m;
	adj = vector<vector<int>>(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;;
		u--, v--;
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		if (!dfsNum[i])
			tarjan(i);
	}
	compGraph = vector<vector<int>>(cnt);
	for (int i = 0; i < n; i++) {
		for (int j : adj[i])
			if (comp[i] != comp[j]) {
				compGraph[comp[i]].push_back(comp[j]);
			}
	}
	for (int i = 0; i < cnt; i++) {
		dfs(i);
	}
	vector<int>ans;
	for (int i = 0; i < cnt; i++) {
		if (bt[i]) {
			ans.insert(ans.end(), all(comps[i]));
		}
	}
	sort(all(ans));
	cout << ans.size() << endl;
	for (int i : ans)cout << i << " ";

}
//"There's a way to do it better - find it". Thomas A. Edison
