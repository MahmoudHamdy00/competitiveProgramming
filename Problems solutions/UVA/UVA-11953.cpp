
// Problem : C - Battleships
// Contest : Virtual Judge - Sheet 7# ( Graph DFS , BFS  ) 1
// URL : https://vjudge.net/contest/372877#problem/C
// Memory Limit : 1024 MB
// Time Limit : 1000 ms
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
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 2000 + 5;
//“Nobody but you have to believe in your dreams to make them a reality.” ― Germany Kent
int n,T = 1;
vector<string>adj;
int vis[101][101];
bool valid(int i, int j) {
	return i < n&& j < n&& i >= 0 && j >= 0;
}
void dfs(int i, int j) {
	if (!valid(i, j)||adj[i][j]=='.'||vis[i][j]==T)return ;
	vis[i][j] = T;
	for (int idx = 0; idx < 4; idx++)dfs(i + dx[idx], j + dy[idx]);
}
int numberOfShips() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adj[i][j] == 'x' && vis[i][j]!=T) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	Ma7moud_7amdy;
	Open_Sesame;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		adj = vector<string>(n+1);
		for (int i = 0; i < n; i++)cin >> adj[i];
		cout <<"Case "<<T++<<": "<< numberOfShips() << endl;
	}
}
