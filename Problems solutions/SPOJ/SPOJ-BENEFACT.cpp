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
const int mod = ll(1e9 + 7), N = 50000 + 5;
//"The secret of getting ahead is getting started". Mark Twain
int n, T = 0, vis[N], ans = 0, from = -1;
vector<vector<pair<int, int>>> adj;
int dfs(int node, int curLen) {
	if (curLen > ans) {
		ans = curLen;
		from = node;
	}
	vis[node] = T;
	int mx = 0;
	for (auto nxt : adj[node]) {
		if (vis[nxt.first] == T)
			continue;
		mx = max(mx, dfs(nxt.first, curLen + nxt.second));
	}
	return mx;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int t;
	cin >> t;
	while (t-- && ++T) {
		from = -1;
		ans = 0;
		cin >> n;
		adj = vector<vector<pair<int, int>>>(n + 1);
		for (int i = 1, u, v, w; i < n; i++) {
			cin >> u >> v >> w;
			adj[u].push_back( { v, w });
			adj[v].push_back( { u, w });

		}
		dfs(1, 0);
		T++;
		dfs(from, 0);
		cout << ans << endl;
	}
	return 0;
}
//"There's a way to do it better - find it". Thomas A. Edison
