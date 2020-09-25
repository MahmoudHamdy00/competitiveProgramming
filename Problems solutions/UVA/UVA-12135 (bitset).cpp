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
vector<int> adj;
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int t, T = 0;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		adj = vector<int>(m);

		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			int tmp = 0;
			for (int j = 0, bulb; j < k; j++) {
				cin >> bulb;
				tmp |= 1 << bulb;
			}
			adj[i] = tmp;
		}

		int q;
		string s;
		cin >> q;
		set<int> wanted;
		vector<int> queries(q);
		map<int, int> ans, vis;
		for (int i = 0; i < q; i++) {
			cin >> s;
			bitset<15> bt;
			reverse(all(s));
			for (int i = 0; i < (int) s.size(); i++)
				bt[i] = s[i] - '0';
			int tmp = bt.to_ulong();
			wanted.insert(tmp);
			queries[i] = tmp;
			ans[tmp] = INT_MAX;

		}
		queue<int> qu;
		qu.push(0);
		int dep = 0, sz;
		int cur;
		for (sz = 1, dep = 0; !qu.empty(); dep++, sz = qu.size()) {
			while (sz--) {
				cur = qu.front(), qu.pop();
				if (wanted.find(cur) != wanted.end()) {
					ans[cur] = min(ans[cur], dep);
				}
				for (int sw : adj) {
					int tmp = cur ^ sw;
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
