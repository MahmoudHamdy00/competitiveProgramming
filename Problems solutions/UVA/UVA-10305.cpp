
// Problem : F - Ordering Tasks
// Contest : Virtual Judge - Sheet  ( Graph DFS , BFS  ) 1
// URL : https://vjudge.net/contest/372877#problem/F
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define Ma7moud_7amdy                 \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define Open_Sesame Open()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(arr, x) memset(arr, x, sizeof arr)
#define endl "\n"
#define watch(x) cout << #x << " = " << x << endl;
#define RT(x) return cout << (x), 0;
#define Accepted 0
typedef long long ll;
typedef vector<int> vi;
const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
void Open()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 2000 + 5;
//“Nobody but you have to believe in your dreams to make them a reality.” ― Germany Kent
int n, m,T=1;
vector<vector<int>>adj;
vector<int>top;
int vis[151];
void dfs(int node) {
	vis[node] = T;
	for (int child : adj[node]) {
		if (vis[child]!=T) {
			dfs(child);
		}
	}
	top.push_back(node);
}
int main()
{
	Ma7moud_7amdy;
	Open_Sesame;
	while (cin >> n >> m) {

		T++;
		top.clear();
		if (n == m && n == 0)break;
		adj = vector<vector<int>>(n + 1);
		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] != T)
				dfs(i);
		}
		reverse(all(top));
		cout << top[0];
		for (int i = 1; i < top.size(); i++)cout << " " << top[i];
		cout << endl;
	}
}
