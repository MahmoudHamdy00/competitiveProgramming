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
const int mod = ll(1e9 + 7), N = 2000 + 5;
//"The secret of getting ahead is getting started". Mark Twain

int n, m, curdfsNum = 0, curComp;
vector<vector<int>> adj;
int inStack[N], lowLink[N], dfsNum[N], comp[N];
stack<int> st;
void tarjan(int node, int per) {
	lowLink[node] = dfsNum[node] = ++curdfsNum;
	st.push(node), inStack[node] = 1;
	for (auto child : adj[node]) {
		if (!dfsNum[child]) {
			tarjan(child, node);
			lowLink[node] = min(lowLink[node], lowLink[child]);
		}
		else if (inStack[child])
			lowLink[node] = min(lowLink[node], dfsNum[child]);
	}
	if (lowLink[node] == dfsNum[node]) {
		int x = -1;
		curComp++;
		while (x != node) {
			x = st.top(), st.pop(), inStack[x] = 0;
		}
	}
}
int main() {
	Ma7moud_7amdy;
	Open_Sesame;
	while (cin >> n >> m && n && m) {
		curdfsNum = curComp = 0;
		memset(lowLink, 0, sizeof lowLink);
		memset(dfsNum, 0, sizeof dfsNum);
		memset(inStack, 0, sizeof inStack);
		memset(comp, 0, sizeof comp);
		st = stack<int>();
		adj = vector<vector<int>>(n);
		for (int i = 0, u, v, p; i < m; i++) {
			cin >> u >> v >> p;
			u--, v--;
			adj[u].push_back(v);
			if (p == 2)
				adj[v].push_back(u);
		}
		for (int i = 0; i < n; i++) {
			if (!dfsNum[i])
				tarjan(i, -1);
		}
		cout << (curComp == 1 ? 1 : 0) << endl;
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
