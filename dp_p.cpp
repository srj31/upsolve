#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e5+5;
vector<int> adj[mxn];
vector<int> vis(mxn);
long long int dp[mxn][2];
const int modi = 1e9+7;

void add_mod(long long int& a, long long int b){
	a+=b;
	if(a>=modi)
		a-=modi;
}

void dfs(int u,int p=-1){
	vis[u] = 1;
	// cout << u << endl;
	if(adj[u].size()==1 && p !=-1){
		dp[u][0] = dp[u][1] = 1;
		// cout << u << endl;
		return;
	}

	long long int ifwhite =1,ifblack = 1;
	for(auto v:adj[u]){
		if(!vis[v]){
			dfs(v,u);
			ifwhite = ifwhite*(dp[v][1]+dp[v][0])%modi;
			ifblack = ifblack*(dp[v][0])%modi;
		}
	}
	add_mod(dp[u][0],ifwhite);
	add_mod(dp[u][1],ifblack);
}


int main(){
	int n;
	cin >> n;
	for(int i =0;i<n-1;i++){
		int u,v;
		cin >> u >> v;--u,--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(n==1){
		cout << 2 << endl;return 0;
	}
	dfs(0);
	add_mod(dp[0][0],dp[0][1]);
	cout << dp[0][0] <<endl;
}