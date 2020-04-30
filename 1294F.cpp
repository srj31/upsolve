#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN = 2e5+10;
vector<int> par(mxN);
vector<int> adj[mxN];

pii dfs(int u,int p=-1,int d = 0){
	pii res = mp(d,u); // distance from the starting node and the node associated with it.
	for(auto v:adj[u]){
		if(v==p)continue;
		par[v] = u;
		res = max(res, dfs(v,u,d+1));
	}
	return res;
}

vector<int> vis(mxN);
pii dfs2(int u,int p=-1,int d=0){
	vis[u] =1;
	pii res = mp(d,u);
	for(auto v:adj[u]){
		if(!vis[v]){
			res = max(res,dfs2(v,u,d+1));
		}
	}
	return res;
}
void solve(){
	int n;
	cin >> n;
	for(int i =0,u,v;i<n-1;i++){
		cin >> u >> v, --u , --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	pii da = dfs(0);
	pii db = dfs(da.se);
	vector<int> dia;
	int curr = db.se;
	while(curr!=da.se){
		dia.pb(curr);
		curr = par[curr];
	}
	dia.pb(da.se);

	for(auto e:dia){
		vis[e]=1;
	}
	int sz = dia.size();
	pii mx = mp(-1,-1);
	for(int i =1;i<sz-1;i++){
		mx = max(mx,dfs2(dia[i]));
	}

	cout << dia.size()-1+mx.fi << "\n" << dia[0]+1 << " " << mx.se+1 << " " << dia.back()+1 << endl;

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}