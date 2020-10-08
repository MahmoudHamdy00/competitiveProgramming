#include<bits/stdc++.h>
using namespace std;
#define Ma7moud_7amdy ios_base::sync_with_stdio(false);  cin.tie(NULL);cout.tie(NULL);
#define Open_Sesame Open()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define endl "\n"
typedef long long ll;
void Open() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 15 + 5;
//"The secret of getting ahead is getting started". Mark Twain
int vis[N][2000], T = 0;
pair<int, int> prv[N][2000];
struct data {
	int id, rooms;
	vector<int> path;
	data(int id, int rooms, vector<int> path) {
		this->id = id;
		this->rooms = rooms;
		this->path = path;
	}
};
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int r, d, s, id = 0;
	while (cin >> r >> d >> s) {
		memset(prv, -1, sizeof prv);
		T++;
		if (r == d && r == s && s == 0)
			break;
		vector<vector<int>> doors(r + 1), lights(r + 1);
		for (int i = 0, u, v; i < d; i++) {
			cin >> u >> v;
			doors[u].push_back(v);
			doors[v].push_back(u);
		}
		for (int i = 0, u, v; i < s; i++) {
			cin >> u >> v;
			lights[u].push_back(v);
		}

		queue<pair<int, int>> q;
		int ans = -1;
		q.push( { 1, 1 });
		bool search = 1;
		int dep = 0;
				vis[1][1] = T;
		for (int sz = 1; search && !q.empty(); sz = q.size(), dep++) {
			while (sz--) {

				int id = q.front().first;
				int rooms = q.front().second;
				q.pop();
				if (rooms == (1 << (r - 1))) {
					ans = dep;
					search = 0;
					break;
				}
				for (int nxt : doors[id]) {
					if (nxt == id)
									continue;
					bool state = (rooms & (1 << (nxt - 1)));
					if (vis[nxt][rooms] != T) {
						if (state) {
							prv[nxt][rooms] = { id, rooms };
							q.push( { nxt, rooms });
							vis[nxt][rooms] = T;

						}
					}
				}
				for (int nxt : lights[id]) {
					if (nxt == id)
						continue;
					int newRooms = rooms ^ (1 << (nxt - 1));
					if (vis[id][newRooms] != T) {
						q.push( { id, newRooms });
						vis[id][newRooms] = T;
						prv[id][newRooms] = { id, rooms };

					}
				}

			}
		}
		cout << "Villa #" << ++id << endl;
		if (search) {
			cout << "The problem cannot be solved.\n\n";
			continue;
		}
		vector<string> route;
		int id = r;
		int rooms = (1 << (r - 1));
		pair<int, int> cur = prv[id][rooms];
		while (!(cur.first == -1&&cur.second==-1)) {
			if (rooms == cur.second) {
				route.push_back("- Move to room " + to_string(id) + ".");
			} else {
				bitset<32> old = cur.second, nw = rooms;
				for (int i = 0; i < 11; i++) {
					if (old[i] && !nw[i])
						route.push_back("- Switch off light in room " + to_string(i + 1) + ".");
					else if (!old[i] && nw[i])
						route.push_back("- Switch on light in room " + to_string(i + 1) + ".");
				}
			}
			id = cur.first;
			rooms = cur.second;
			cur = prv[cur.first][cur.second];

		}
		reverse(all(route));
		cout << "The problem can be solved in " << ans << " steps:\n";
		for (int i = 0, sz = (int) route.size(); i < sz; i++)
			cout << route[i] << "\n";
		cout << endl;
	}

}
//"There's a way to do it better - find it". Thomas A. Edison