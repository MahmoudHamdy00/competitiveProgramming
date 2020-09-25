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
const int mod = ll(1e9 + 7), N = 1000 + 5;
//“The secret of getting ahead is getting started”. Mark Twain
int n,l,c,lec,mem[N][N],vis[N][N],T=0;
vector<int>v;
int solve(int i,int j){
	if(i==lec)return j==n?0:1e9;
	int &ret=mem[i][j];
	if(vis[i][j]==T)return ret;
	vis[i][j]=T;
	ret = 1e9;
	int sum=0;
	for(int k=j;k<n;k++){
		sum+=v[k];

		if(sum<=l){
			int t=l-sum;
			if(t==0)t=0;
			else if(t<=10)t=-c;
			else t=(t-10)*(t-10);
			ret = min(solve(i + 1, k + 1) + t,ret);
		}
		else break;
	}
	return ret;
}
int main() {
	Ma7moud_7amdy
	;
	Open_Sesame;
	while (cin >> n && n && ++T) {
		v = vector<int>(n);

		cin >> l >> c;

		for (int i = 0; i < n; i++) {
			cin >> v[i];

		}
		int i = 0, sum = 0;
		lec = 1;
		while (i < n) {
			if (sum + v[i] <= l) {
				sum += v[i];
			} else {
				sum = v[i];
				lec++;
			}
			i++;
		}
		if (T>1)
			cout << "\n";
		cout << "Case " << T << ":\n";
		cout << "Minimum number of lectures: "<<lec << endl;
		cout << "Total dissatisfaction index: "<<solve(0, 0)<< endl;

	}
	return 0;
}
//“There's a way to do it better - find it”. Thomas A. Edison
