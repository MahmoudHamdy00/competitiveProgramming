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
const int mod = ll(1e4), N = 20 + 5;
//"The secret of getting ahead is getting started". Mark Twain
const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
char arr[N][N], land;
int n, m;
int T = 0, vis[N][N];
void fix(int &x) {
	if (x >= m)
		x = 0;
	else if (x < 0)
		x = m - 1;
}
int floodFill(int i, int j) {
	int ret = 0;
	for (int idx = 0; idx < 4; idx++) {
		int x = i + dx[idx];
		int y = j + dy[idx];
		if (x >= n || x < 0)
			continue;
		fix(y);
		if (vis[x][y] != T && arr[x][y] == land) {
			vis[x][y] = T;
			ret += floodFill(x, y) + 1;
		}
	}
	return ret;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	while (cin >> n >> m && ++T) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int x, y;
		cin >> x >> y;
		land = arr[x][y];
		floodFill(x, y);
		vis[x][y]=T;
		int ans = 0;
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] != T && arr[i][j] == land)
					ans = max(ans, floodFill(i, j)), ok = 1;
			}
		}
		if (ans == 0)
			cout << ok << endl;
		else
			cout << ans << endl;
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
