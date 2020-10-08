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
//"The secret of getting ahead is getting started". Mark Twain

int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int n;
	while (cin >> n && n) {
		string a, b;
		map<string, string> mp;
		set<string> vis;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			mp[a] = b;
		}
		string s, k;
		cin >> s >> k;
		queue<string> q;
		q.push(s);
		bool search = 1;
		int dep = 0, ans = INT_MAX;
		for (int sz = 1; search && !q.empty(); sz = q.size(), dep++) {
			while (sz--) {
				string cur = q.front();
				q.pop();
				if (cur == k) {
					ans = dep;
					search = 0;
					break;
				}
				if (vis.find(cur) != vis.end())
					continue;
				vis.insert(cur);
				string tmp = cur;
				for (auto it : mp) {
					cur = tmp;
					auto idx = cur.find(it.first);
					int sz = it.first.size() + 20;
					while (idx != string::npos&&sz--) {
						cur.replace(idx, it.first.size(), it.second);
						idx = cur.find(it.first, idx + it.second.size());

					}
					if (vis.find(cur) == vis.end()&&cur.size()<=k.size())
						q.push(cur);
				}
			}
		}
		cout << (ans == INT_MAX ? -1 : ans) << endl;

	}
}
//"There's a way to do it better - find it". Thomas A. Edison
