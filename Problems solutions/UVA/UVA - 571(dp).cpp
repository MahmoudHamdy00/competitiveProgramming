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
const int mod = ll(1e4), N = 1000 + 55;
//"The secret of getting ahead is getting started". Mark Twain
int fillA = 1, fillB = 2, pourAB = 3, pourBA = 4, emptyA = 5, emptyB = 6,
		success = 7;
int CA, CB, n, T = 0, vis[N][N], mem[N][N];
int solve(int ca, int cb) {
	if (cb == n)
		return 0;
	int &ret = mem[ca][cb];
	if (vis[ca][cb] == T)
		return ret;
	vis[ca][cb] = T;
	ret = 1e8;
	//fill
	ret = min(ret, 1 + solve(CA, cb));

	ret = min(ret, 1 + solve(ca, CB));

	//empty
	ret = min(ret, 1 + solve(0, cb));

	ret = min(ret, 1 + solve(ca, 0));

	//pour
	int remA = CA - ca, remB = CB - cb;
	ret = min(ret, 1 + solve(min(ca + cb, CA), max(0, cb - remA)));

	ret = min(ret, 1 + solve(max(0, ca - remB), min(ca + cb, CB)));

	return ret;
}
void build(int ca, int cb) {
	if (cb == n) {
		cout << "success\n";
		return;
	}
	int ret = mem[ca][cb];
	//fill
	if (ret == 1 + solve(CA, cb)) {
		cout << "fill A\n";
		return build(CA, cb);
	}

	if (ret == 1 + solve(ca, CB)) {
		cout << "fill B\n";
		return build(ca, CB);
	}

	//empty
	if (ret == 1 + solve(0, cb)) {
		cout << "empty A\n";
		build(0, cb);
		return;
	}
	if (ret == 1 + solve(ca, 0)) {
		cout << "empty B\n";
		return build(ca, 0);
	}
	//pour
	int remA = CA - ca, remB = CB - cb;
	if (ret == 1 + solve(min(ca + cb, CA), max(0, cb - remA))) {
		cout << "pour B A\n";
		return build(min(ca + cb, CA), max(0, cb - remA));
	}
	if (ret == 1 + solve(max(0, ca - remB), min(ca + cb, CB))) {
		cout << "pour A B\n";
		return build(max(0, ca - remB), min(ca + cb, CB));
	}
	return;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	while (cin >> CA >> CB >> n && ++T) {
		solve(0, 0);
		build(0, 0);
	}
}
//"There's a way to do it better - find it". Thomas A. Edison
