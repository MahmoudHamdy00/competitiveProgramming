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
const int mod = ll(1e4), N = 1e4 + 5;
//"The secret of getting ahead is getting started". Mark Twain
int vis[N], mem[N];
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int l, u, r, T = 0;
	while (cin >> l >> u >> r) {
		if (!l && !u && !r)
			break;
		bool ok = 1;
		cout << "Case " << ++T << ": ";
		vector<int> v(r);
		for (int i = 0; i < r; i++)
			cin >> v[i];
		queue<int> q;
		q.push(l);
		vis[l] = T;
		int press = 0;
		for (int cur, sz = 1; ok && !q.empty(); sz = (int) q.size(), press++) {
			while (sz--) {
				cur = q.front();
				q.pop();
				if (cur == u) {
					cout << press << endl;
					ok = 0;
					break;
				}
				for (int i = 0; i < r; i++) {
					int tmp = cur + v[i];
					if (tmp >= mod)
						tmp -= mod;
					if (vis[tmp] != T) {
						q.push(tmp);
						vis[tmp] = T;
					}
				}
			}
		}

		if (ok)
			cout << "Permanently Locked\n";
	}
	return 0;
}
//"There's a way to do it better - find it". Thomas A. Edison
