// Problem : X - Prime Path
// Contest : Virtual Judge - Sheet  ( Graph DFS , BFS  ) 1
// URL : https://vjudge.net/contest/372877#problem/X
// Memory Limit : 1572 MB
// Time Limit : 2000 ms
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
const int mod = ll(1e9 + 7), N = 1e5 + 5;
//“The secret of getting ahead is getting started”. Mark Twain
int vis[N], T = 0;
vector<bool> prime(N, 1);
vector<vector<int>> adj(N);
void sieve() {
	prime[0] = prime[1] = 0;
	for (ll i = 4; i < N; i += 2)
		prime[i] = 0;

	for (ll i = 2; i * i < N; i++)
		if (prime[i])
			for (int j = i * i; j < N; j += 2 * i)
				prime[j] = 0;
}
void build() {
	for (int cur = 1000; cur <= 9999; cur++) {
		if (!prime[cur])
			continue;
		string org = to_string(cur);
		for (int d = 0; d < 4; d++) {
			string tmp = org;
			for (char ch = '0' + (d == 0); ch <= '9'; ch++) {
				if (ch == org[d])
					continue;
				tmp[d] = ch;
				int num = stoi(tmp);
				if (prime[num])
					adj[cur].push_back(num);
			}
		}
	}
}

int BFS(int from, int to) {
	queue<int> q;
	q.push(from);
	for (int sz = 1, cost = 0; !q.empty(); cost++, sz = q.size()) {
		while (sz--) {
			int cur = q.front();
			q.pop();
			vis[cur] = T;
			if (cur == to)
				return cost;

			for (int nxt : adj[cur])
				if (vis[nxt] != T) {
					q.push(nxt);
				}
		}
	}
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	sieve();
	build();
	int t;
	cin >> t;
	while (t-- && ++T) {
		int from, to;
		cin >> from >> to;
		cout << BFS(from, to) << endl;
	}
	return 0;
}
//“There's a way to do it better - find it”. Thomas A. Edison
