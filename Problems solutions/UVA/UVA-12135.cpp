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
vector<vector<int>> adj;
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int t, T = 0;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		adj = vector<vector<int>>(m);

		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			adj[i] = vector<int>(k);
			for (int j = 0; j < k; j++) {
				cin >> adj[i][j];
			}
		}
		int q;
		string s;
		cin >> q;
		set<string> wanted;
		vector<string> queries(q);
		map<string, int> ans, vis;
		for (int i = 0; i < q; i++) {
			cin >> s;
			reverse(all(s));
			queries[i] = s;
			wanted.insert(s);
			ans[s] = INT_MAX;
		}
		queue<string> qu;
		qu.push(string(n, '0'));
		int dep = 0, sz;
		string cur;
		for (sz = 1, dep = 0; !qu.empty(); dep++, sz = qu.size()) {
			while (sz--) {
				cur = qu.front(), qu.pop();
				if (wanted.find(cur) != wanted.end()) {
					ans[cur] = min(ans[cur], dep);
				}
				for (auto sw : adj) {
					string tmp = cur;
					for (int j : sw) {
						tmp[j] = tmp[j] == '1' ? '0' : '1';
					}
					if (vis.find(tmp) == vis.end()) {
						vis[tmp];
						qu.push(tmp);
					}
				}
			}
		}
		cout << "Case " << ++T << ":\n";
		for (int i = 0; i < q; i++) {
			if (ans[queries[i]] != INT_MAX) {
				cout << ans[queries[i]] << endl;
			} else
				cout << -1 << endl;
		}
		cout << endl;
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
