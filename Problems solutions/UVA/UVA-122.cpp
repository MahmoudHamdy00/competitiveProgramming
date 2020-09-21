// Problem : K - Trees on the level
// Contest : Virtual Judge - Sheet  ( Graph DFS , BFS  ) 1
// URL : https://vjudge.net/contest/372877#problem/K
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
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
const int mod = ll(1e9 + 7), N = 2000 + 5;
//“The secret of getting ahead is getting started”. Mark Twain
vector<vector<pair<string, int>>> adj;
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;

	string in;
	while (cin >> in && in != "()") {
		adj = vector<vector<pair<string, int>>>(300);
		map<string, bool> vis;
		bool ok = 1;
		int idx;
		do {
			in.pop_back();
			idx = in.find(',');
			int val = stoi(in.substr(1, idx));
			string pos = in.substr(idx + 1);
			if (vis.find(pos) != vis.end()) {
				ok = 0;
			} else {
				adj[(int) pos.size()].push_back( { pos, val });
				vis[pos];
			}
		} while (cin >> in && in != "()");

		if (ok && vis.find("") != vis.end()) {
			vector<vector<pair<string, int>>> ans;
			ans.push_back( { adj[0][0] });
			for (int i = 1; ok && i < 300; i++) {
				vector<pair<string, int>> tmp;
				for (auto it : adj[i]) {
					string prv = it.first;
					prv.pop_back();
					if (vis.find(prv) == vis.end()) {
						ok = 0;
						break;
					}
					tmp.push_back(it);
				}
				ans.push_back(tmp);
			}
			if (ok) {
				cout << adj[0][0].second;
				for (int i = 1; ok && i < 300; i++) {
					if (adj[i].empty()) {
						break;
					} else {
						sort(all(adj[i]));
						for (int it = 0; it < (int) adj[i].size(); it++) {
							cout << " " << adj[i][it].second;
						}
					}
				}
				cout << endl;
			} else
				cout << "not complete\n";

		} else
			cout << "not complete\n";
	}
	return 0;
}
//“There's a way to do it better - find it”. Thomas A. Edison
