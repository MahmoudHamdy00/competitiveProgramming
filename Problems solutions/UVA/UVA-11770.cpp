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
const int mod = ll(1e4), N = 10000 + 55;
//"The secret of getting ahead is getting started". Mark Twain
int vis[N], T = 0;
vector<vector<int>> adj;
void dfs(int node) {
	vis[node] = T;
	for (int child : adj[node]) {
		if (vis[child] != T) {
			dfs(child);
		}
	}
	return;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int t, id = 0;
	cin >> t;
	while (t-- && ++T) {
		int n, m, u, v;
		cin >> n >> m;
		adj = vector<vector<int>>(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
		}
		vector<int> starts;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] != T) {
				dfs(i);
				starts.push_back(i);
			}
		}
		T++;
		for (int i = (int) starts.size() - 1; i != -1; i--) {
			if (vis[starts[i]] != T) {
				ans++;
				dfs(starts[i]);
			}
		}
		cout << "Case " << ++id << ": " << ans << endl;
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
