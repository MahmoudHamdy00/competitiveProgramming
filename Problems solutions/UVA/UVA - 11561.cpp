// Problem : S - Getting Gold
// Contest : Virtual Judge - Sheet  ( Graph DFS , BFS  ) 1
// URL : https://vjudge.net/contest/372877#problem/S
// Memory Limit : 1024 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
const int mod = ll(1e9 + 7), N = 50 + 5;
//“The secret of getting ahead is getting started”. Mark Twain
const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
char grid[N][N];
int vis[N][N], T = 0, h, w;
bool valid(int i, int j) {
	if (grid[i][j] == '#' || grid[i][j] == 'T' || vis[i][j] == T)
		return 0;
	return 1;
}
int BFS(int from, int to) {
	queue<pair<int, int>> q;
	q.push( { from, to });
	int gold = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		vis[x][y] = T;
		if (grid[x][y] == 'G')
			gold++;
		bool ok = 0;
		for (int id = 0; id < 4; id++) {
			if (grid[x + dx[id]][y + dy[id]] == 'T') {
				ok = 1;
				break;
			}
		}
		if (ok)
			continue;

		for (int id = 0; id < 4; id++) {
			if (valid(x + dx[id], y + dy[id])) {
				q.push( { x + dx[id], y + dy[id] });
				vis[x + dx[id]][y + dy[id]] = T;
			}
		}
	}
	return gold;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;

	while (cin >> w >> h && ++T) {
		int x, y;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'P')
					x = i, y = j;
			}
		}
		cout << BFS(x, y) << endl;
	}
	return 0;
}
//“There's a way to do it better - find it”. Thomas A. Edison
