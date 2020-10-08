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
const int mod = ll(1e9 + 7), N = 1e5 + 5;
//"The secret of getting ahead is getting started". Mark Twain
int vis[N], T = 0;
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int n;
	while (cin >> n) {
		cin.ignore();
		vector<vector<int>> adj(n + 1);
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			stringstream in(s);
			int id, ID;
			in >> ID;
			char ch;
			while (in >> ch) {
				if (in >> id)
					adj[ID].push_back(id);
			}
		}
		cout << "-----\n";
		int m;
		int u, v;
		cin >> m;
		while (m--) {
			T++;
			cin >> u >> v;
			queue<pair<int, vector<int>>> q;
			vector<int> route;
			q.push( { u, { u } });
			bool search = 1;
			int dep = 0;
			for (int sz = 1; search && !q.empty(); sz = q.size(), dep++) {
				while (sz--) {
					int cur = q.front().first;
					vector<int> tmp = q.front().second;
					q.pop();
					vis[cur] = T;
					if (cur == v) {
						route = tmp;
						search = 0;
						break;
					}
					for (int nxt : adj[cur]) {
						if (vis[nxt] != T) {
							tmp.push_back(nxt);
							q.push( { nxt, tmp });
							tmp.pop_back();
						}
					}
				}
			}
			if (route.empty()) {
				cout << "connection impossible\n";
				continue;
			}

			for (int i = 0, sz = (int) route.size(); i < sz; i++)
				cout << route[i] << " \n"[i == sz - 1];
		}
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
