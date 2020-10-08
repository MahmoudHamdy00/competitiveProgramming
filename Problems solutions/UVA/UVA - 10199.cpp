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
const int mod = ll(1e9 + 7), N = 200 + 5;
//"The secret of getting ahead is getting started". Mark Twain
int n, curdfsNum = 0, cnt;
vector<vector<int>> adj;
int lowLink[N], dfsNum[N], art[N];
int root;
void tarjan(int node, int per) {
	lowLink[node] = dfsNum[node] = ++curdfsNum;
	for (auto child : adj[node]) {
		if (!dfsNum[child]) {
			tarjan(child, node);
			lowLink[node] = min(lowLink[node], lowLink[child]);
			if (lowLink[child] >= dfsNum[node]) {
				if (node == root)
					root = -1;
				else
					art[node] = 1;
			}
		}
		else if (child != per)
			lowLink[node] = min(lowLink[node], dfsNum[child]);
	}

}
int main() {
	Ma7moud_7amdy;
	Open_Sesame;
	int T = 0;
	while (cin >> n && n) {
		curdfsNum = cnt = 0;
		memset(lowLink, 0, sizeof lowLink);
		memset(dfsNum, 0, sizeof dfsNum);
		memset(art, 0, sizeof art);
		adj = vector<vector<int>>(100);

		map<string, int>id;
		map<int, string>revId;

		string str, u, v;
		int sz = -1;
		for (int i = 0; i < n; i++) {
			cin >> u;
			if (id.find(u) == id.end())
				id[u] = ++sz, revId[sz] = u;
		}
		int r;
		cin >> r;
		for (int i = 0; i < r; i++) {
			cin >> u >> v;
			adj[id[u]].push_back(id[v]);
			adj[id[v]].push_back(id[u]);
		}
		for (int i = 0; i < n; i++) {
			if (!dfsNum[i])
				root = i, tarjan(i, -1);
		}
		vector<string>cameras;
		for (int i = 0; i < n; i++) {
			if (art[i]) {
				cameras.push_back(revId[i]);
			}

		}
		sort(all(cameras));
		if (T)cout << endl;
		cout << "City map #" << ++T << ": " << cameras.size() << " camera(s) found" << endl;
		for (int i = 0; i < cameras.size(); i++) {
			cout << cameras[i] << "\n";
		}
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
