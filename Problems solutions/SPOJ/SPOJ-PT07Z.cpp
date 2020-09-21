// Problem : L - Longest path in a tree
// Contest : Virtual Judge - Sheet  ( Graph DFS , BFS  ) 1
// URL : https://vjudge.net/contest/372877#problem/L
// Memory Limit : 1572 MB
// Time Limit : 500 ms
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
void Open() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 2000 + 5;
//“Nobody but you have to believe in your dreams to make them a reality.” ― Germany Kent
int n, mx = 0, nod = 0, T = 1;
vector<vector<int>> adj;
vector<int> top;
int vis[100000];
void dfs(int node, int len = 0) {
	vis[node] = T;
	if (len > mx)
		mx = len, nod = node;
	for (int child : adj[node]) {
		if (vis[child] != T) {
			dfs(child, len + 1);
		}
	}
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	cin >> n;
	adj = vector<vector<int>>(n + 1);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	T++;
	dfs(nod);
	cout << mx;
}
//“There's a way to do it better - find it”. Thomas A. Edison
