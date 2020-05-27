#include<bits/stdc++.h>
using namespace std;
const int mxn  = 2e5;
vector<int> adj[mxn];
int in[mxn],out[mxn],mark[mxn];

void dfs(int u , int p=-1){
	if(mark[u])
		in[u] = 0;
	for(auto v:adj[u]){
		if(v==p) continue;
		dfs(v,u);
		in[u] = max(in[u],1+in[v]);
	}
}

void dfs2(int u, int p=-1){
	if(mark[u] && in[u]<0)
		out[u] = 0;

	int mx1,mx2;
	mx1 = mx2 = -mxn;
	for(auto v:adj[u]){
		if(v==p) continue;
		if(in[v]>mx1){ mx2 = mx1;mx1 = in[v];}
		else if(in[v]>mx2){ mx2 = in[v];}
	}

	for(auto v:adj[u]){
		if(v==p) continue;
		int use = mx1;
		if(use==in[v]) use = mx2;
		out[v] = max(out[v],max(1+out[u],2+use));
		// out[v] = max(2+use, 1+out[u]);
		if (mark[v] && out[v]<0)out[v] = 0;
		dfs2(v,u);
	}	
}
int main(){
	int n,m,d;
	cin >> n >> m >> d;
	for(int i =0;i<n;i++){
		in[i] = -mxn;
		out[i] = -mxn;
	}
	for(int i =0;i<m;i++){
		int b;
		cin >> b;
		--b;
		mark[b]++;
	}
	for(int i =0;i<n-1;i++){
		int u,v;
		cin >> u >> v;--u,--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// cout << 'h' << endl;
	dfs(0);
	out[0] = -mxn;
	if(mark[0]) out[0] = 0;
	dfs2(0);
	int ans = 0;
	for(int i =0;i<n;i++){
			// cout << i << " " << in[i] << " " << out[i] << endl;

		if(in[i]<=d && out[i]<=d){
			ans++;
		}
	}
	cout << ans << endl;
}