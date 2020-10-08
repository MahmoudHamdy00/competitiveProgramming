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
const int mod = ll(1e9 + 7), N = 50 + 5;
//"The secret of getting ahead is getting started". Mark Twain
bool arr[55][55], vis[55][55][4];
const int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int m, n;
struct data {
	int x, y, orientation;
	data(int x, int y, int orientation) {
		this->x = x;
		this->y = y;
		this->orientation = orientation;
	}
};
inline bool valid(int i, int j) {
	return i > 0 && j > 0 && i < m && j < n && !arr[i - 1][j - 1]
			&& !arr[i - 1][j] && !arr[i][j - 1] && !arr[i][j];
}

map<string, int> direction { { "north", 0 }, { "east", 1 }, { "south", 2 }, {
		"west", 3 } };

int BFS(int bx, int by, int ex, int ey, int orientation) {
	queue<data> q;
	q.push(data(bx, by, orientation));
	int sz = 1, dep = -1;
	do {
		sz = q.size(), dep++;
		while (sz--) {
			data cur = q.front();
			q.pop();
			if (cur.x == ex && cur.y == ey) {
				return dep;
			}

			if (vis[cur.x][cur.y][cur.orientation])
				continue;
			vis[cur.x][cur.y][cur.orientation] = 1;

			//TURN
			int right = (cur.orientation + 1) % 4;
			int left = (cur.orientation + 3) % 4;

			q.push(data(cur.x, cur.y, right));
			q.push(data(cur.x, cur.y, left));
			//GO
			int x = cur.x, y = cur.y;
			for (int i = 1; i <= 3; i++) {
				x = cur.x + dx[cur.orientation] * i;
				y = cur.y + dy[cur.orientation] * i;
				if (!valid(x, y))
					break;
				q.push(data(x, y, cur.orientation));
			}

		}
	} while (q.size());

	return -1;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	while (cin >> m >> n && n && m) {
		memset(vis, 0, sizeof vis);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		}
		int bx, by, ex, ey;
		string orientation;
		cin >> bx >> by >> ex >> ey;
		cin >> orientation;
		int ans = -1;
		if (valid(bx, by)) {
			ans = BFS(bx, by, ex, ey, direction[orientation]);
		}
		cout << ans << endl;
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
