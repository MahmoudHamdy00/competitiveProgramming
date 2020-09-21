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
const int mod = ll(1e9 + 7), N = 5000 + 5;
//"The secret of getting ahead is getting started". Mark Twain
int mem[N][N], vis[N][N], T = 0;
vector<int> root;
vector<vector<int>> adj;

int dfs(int node, int per) {
	int &ret = mem[node][per];
	if (vis[node][per] == T)
		return ret;
	ret = 0;
	vis[node][per] = T;
	for (auto nxt : adj[node]) {
		if (nxt == per)
			continue;
		ret = max(dfs(nxt, node) + 1, ret);
	}
	return ret;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int n;
	while (cin >> n && ++T) {
		root = vector<int>(n + 1);
		adj = vector<vector<int>>(n + 1);
		for (int i = 1, k; i <= n; i++) {
			cin >> k;
			for (int j = 0, tmp; j < k; j++) {
				cin >> tmp;
				adj[i].push_back(tmp);
				adj[tmp].push_back(i);
			}
		}
		int mn = INT_MAX, mx = 0;
		for (int i = 1; i <= n; i++) {
			root[i] = dfs(i, -1);
			mn = min(root[i], mn);
			mx = max(root[i], mx);
		}
		vector<int> best, worst;
		for (int i = 1; i <= n; i++) {
			if (root[i] == mn)
				best.push_back(i);
			if (root[i] == mx)
				worst.push_back(i);
		}
		cout << "Best Roots  :";
		for (int i = 0, sz = (int) best.size(); i < sz; i++)
			cout << " " << best[i];
		cout << "\nWorst Roots :";
		for (int i = 0, sz = (int) worst.size(); i < sz; i++)
			cout << " " << worst[i];
		cout << endl;
	}
	return 0;
}
//"There's a way to do it better - find it". Thomas A. Edison
