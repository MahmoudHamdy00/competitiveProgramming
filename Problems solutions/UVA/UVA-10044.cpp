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
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int t;
	cin >> t;
	for (int ts = 1; ts <= t; ts++) {
		int p, n;
		cin >> p >> n;
		string ed = "Erdos, P.", u, v;
		int uID, vID;
		vector<string> paper(p), names(n);
		cin.ignore();
		for (int i = 0; i < p; i++) {
			getline(cin, paper[i]);
			paper[i] = paper[i].substr(0, paper[i].find(':')) + ',';
		}
		map<string, int> mp;
		map<int, string> org;
		auto setID = [&](string s) {
			if (mp.find(s) == mp.end()) {
				int id = mp.size();
				mp[s] = id;
				org[id] = s;
			}
		};
		for (int i = 0; i < n; i++) {
			getline(cin, names[i]);
			setID(names[i]);
		}
		vector<vector<string>> modifiedPaper;
		for (int i = 0; i < p; i++) {
			vector<string> tmp;
			string cur = paper[i];
			auto res = cur.find(',');
			int from = 0;
			while (res != string::npos) {
				res = cur.find(',', res + 1);
				if (res == string::npos)
					break;
				string k = cur.substr(from, res - from);
				setID(k);
				tmp.push_back(k);
				from = res;
				res = cur.find(',', from + 1);
				from += 2;
			}
			modifiedPaper.push_back(tmp);
		}
		vector<vector<int>> adj(mp.size() + 1);
		for (auto tmp : modifiedPaper) {
			for (int j = 0; j < (int) tmp.size(); j++) {
				for (int k = j + 1; k < (int) tmp.size(); k++) {
					u = tmp[j], v = tmp[k];
					uID = mp[u], vID = mp[v];
					adj[uID].push_back(vID);
					adj[vID].push_back(uID);
				}
			}
		}
		queue<string> q;
		vector<int> erdosNumbers(mp.size() + 1);
		map<string, int> vis;
		q.push(ed);
		int sz = 1, curNum = 0;
		while (!q.empty()) {
			while (sz--) {
				string cur = q.front();
				q.pop();
				int id = mp[cur];
				erdosNumbers[id] = curNum;
				for (int i : adj[id]) {
					if (vis.find(org[i]) == vis.end()) {
						q.push(org[i]);
						vis[org[i]];
					}
				}
			}
			sz = q.size(), curNum++;
		}
		cout << "Scenario " << ts << endl;
		for (int i = 0; i < n; i++) {
			int tmp = erdosNumbers[mp[names[i]]];
			cout << names[i] << " ";
			if (tmp)
				cout << tmp << endl;
			else
				cout << "infinity" << endl;
		}
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
