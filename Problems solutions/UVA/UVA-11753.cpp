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
const int mod = ll(1e4), N = 10001;
//"The secret of getting ahead is getting started". Mark Twain
int n, k, T;
vector<int> v;
int solve(int l, int r, int cnt) {
	if(cnt>k)return 1e9;
	if (l > r)
		return cnt;
	int ret = INT_MAX;
	if (v[l] == v[r])
		return ret = solve(l + 1, r - 1, cnt);
	ret = min(ret, solve(l + 1, r, cnt + 1));
	ret = min(ret, solve(l, r - 1, cnt + 1));
	return ret;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int t;
	cin >> t;
	for (T = 1; T <= t; T++) {
		cin >> n >> k;
		v = vector<int>(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int ans = solve(0, n - 1, 0);
		cout << "Case " << T << ": ";
		if (ans == 0)
			cout << "Too easy\n";
		else if (ans > k)
			cout  << "Too difficult\n";
		else
			cout << ans << endl;

	}
}
//"There's a way to do it better - find it". Thomas A. Edison
