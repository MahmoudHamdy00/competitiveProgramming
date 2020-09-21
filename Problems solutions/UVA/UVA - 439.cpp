// Problem : 439 - Knight Moves
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
// Memory Limit : 32 MB
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
bool valid(string pos) {
	return pos[0] >= 'a' && pos[0] <= 'h' && pos[1] >= '1' && pos[1] <= '8';
}

int main() {
	Ma7moud_7amdy
	;
	//Open_Sesame;

	string from, to;
	while (cin >> from >> to) {
		queue<string> q;
		map<string, bool> vis;
		q.push(from);
		auto add = [&](string s) {
			if (valid(s) && vis.find(s) == vis.end()) {
				vis[s];
				q.push(s);
				return;
			}
		};

		bool ok = 0;
		int moves = 0;
		for (int sz = 1; !ok && !q.empty(); moves++, sz = q.size()) {
			while (!ok && sz--) {
				string cur = q.front();
				q.pop();
				if (cur == to) {
					ok = 1;
					break;
				}
				string _1 = cur, _2 = cur, _3 = cur, _4 = cur, _5 = cur, _6 =
						cur, _7 = cur, _8 = cur;

				_1[0] += 2, _1[1]++;
				_2[0] += 2, _2[1]--;
				_3[0] -= 2, _3[1]++;
				_4[0] -= 2, _4[1]--;

				_5[1] += 2, _5[0]++;
				_6[1] += 2, _6[0]--;
				_7[1] -= 2, _7[0]++;
				_8[1] -= 2, _8[0]--;

				add(_1);
				add(_2);
				add(_3);
				add(_4);
				add(_5);
				add(_6);
				add(_7);
				add(_8);

			}
		}
		cout << "To get from " << from << " to " << to << " takes " << --moves
				<< " knight moves.\n";
	}
	return 0;
}
//“There's a way to do it better - find it”. Thomas A. Edison
