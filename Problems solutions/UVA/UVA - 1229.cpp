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
int n, curdfsNum = 0, cnt;
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
		cnt++;
		while (x != node) {
			x = st.top(), st.pop(), inStack[x] = 0;
			comp[x] = cnt - 1;
		}
	}
}
void dfs(int node) {
	if (inStack[node])return;
	inStack[node] = 1;
	for (int child : adj[node]) {
		dfs(child);
	}
}
int main() {
	Ma7moud_7amdy;
	Open_Sesame;
	while (cin >> n && n) {
		curdfsNum = cnt = 0;
		memset(lowLink, 0, sizeof lowLink);
		memset(dfsNum, 0, sizeof dfsNum);
		memset(inStack, 0, sizeof inStack);
		memset(comp, 0, sizeof comp);
		st = stack<int>();
		adj = vector<vector<int>>(100);
		map<string, int>id;
		map<int, string>revId;
		string str, u, v;
		int sz = -1;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			getline(cin, str);
			stringstream in(str);
			in >> u;
			if (id.find(u) == id.end())
				id[u] = ++sz, revId[sz] = u;
			while (in >> v)
			{
				if (id.find(v) == id.end())
					id[v] = ++sz, revId[sz] = v;
				adj[id[u]].push_back(id[v]);
			}
		}
		for (int i = 0; i < n; i++) {
			if (!dfsNum[i])
				tarjan(i, -1);
		}
		memset(inStack, 0, sizeof inStack);
		vector<int>sizeSCC(cnt);
		for (int i = 0; i < n; i++) sizeSCC[comp[i]]++;
		for (int i = 0; i < n; i++) {
			if (sizeSCC[comp[i]] > 1)
			{
				dfs(i);
			}
		}
		vector<string>ans;
		for (int i = 0; i < n; i++) {
			if (inStack[i])
				ans.push_back(revId[i]);
		}

		
		sort(all(ans));
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " \n"[i==ans.size()-1];
		}
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
