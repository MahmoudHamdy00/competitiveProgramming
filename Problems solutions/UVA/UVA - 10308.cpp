// Problem : M - Roads in the North
// Contest : Virtual Judge - Sheet  ( Graph DFS , BFS  ) 1
// URL : https://vjudge.net/contest/372877#problem/M
// Memory Limit : 1024 MB
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
const int mod = ll(1e9 + 7), N = 10000 + 5;
//“The secret of getting ahead is getting started”. Mark Twain
vector<vector<pair<int, int>>> adj;
int ans=0;
int vis[N],T=0;
int DFS(int node,int weight){
	int mx=0;
	vis[node]=T;
	for(auto nxt:adj[node]){
		if(vis[nxt.first]==T)continue;

		int cur=DFS(nxt.first,nxt.second);
		ans=max(ans,mx+cur);
		mx=max(mx,cur);
	}
	return mx+weight;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	string input;
	while (getline(cin, input) && !input.empty()) {
		adj=vector<vector<pair<int, int>>> (N);
		T++;
		ans=0;
		do {
			stringstream in(input);
			int u,v,w;
			in>>u;in>>v;in>>w;

			adj[u].push_back({v,w});
			adj[v].push_back({u,w});

		} while (getline(cin, input) && !input.empty());
		DFS(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
//“There's a way to do it better - find it”. Thomas A. Edison
