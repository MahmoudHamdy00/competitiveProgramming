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
const int mod = ll(1e9 + 7), N = 5000 + 5;
//“The secret of getting ahead is getting started”. Mark Twain
const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int T = 1, TT = 0, black[9][9], white[9][9], vis[9][9];
char board[9][9];
bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < 9 && j < 9;
}
void floodFill(int i, int j, bool state) {
	if (vis[i][j] == T)
		return;
	if (state) {
		white[i][j] = TT;
	} else {
		black[i][j] = TT + 1;
	}
	vis[i][j] = T;
	for (int idx = 0; idx < 4; idx++) {
		int x = i + dx[idx], y = j + dy[idx];
		if (valid(x, y) && (board[x][y] == board[i][j] || board[x][y] == '.')) {
			floodFill(x, y, state);
		}
	}
	return;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	int t;
	cin >> t;
	while (t--) {
		TT += 2;
		for (int i = 0; i < 9; i++) {
			cin >> board[i];
		}
		int wh = 0, bl = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (vis[i][j] != T && board[i][j] == 'O')
					floodFill(i, j, 1);
			}
		}
		T++;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (vis[i][j] != T && board[i][j] == 'X')
					floodFill(i, j, 0);
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++, T++) {
				if (white[i][j] == TT && black[i][j] == TT + 1)
					continue;
				wh += (white[i][j] == TT);
				bl += (black[i][j] == TT + 1);

			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++, T++) {
				if (white[i][j] == TT && black[i][j] == TT + 1) {
					wh += (board[i][j] == 'O');
					bl += (board[i][j] == 'X');
				}

			}
		}
		cout << "Black " << bl << " White " << wh << '\n';
	}
	return 0;
}
//“There's a way to do it better - find it”. Thomas A. Edison
