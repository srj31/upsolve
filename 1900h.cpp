#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
vector<set<int> > adj(mxN);

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i =0;i<m;i++){
		int u,v;
		cin >> u >> v;
		--u,--v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	// create the list of connected to should be smae;
	set<set<int> > con;
	for(int i=0;i<n;i++){
		if(adj[i].size()==0)
{
	cout << -1 << endl;return;
}		con.insert(adj[i]);
	}
	if(con.size()!=3){
		cout << -1 << endl;return;
	}
	map<set<int> ,int > no;
	int curr = 1;
	for(auto e:con){
		no[e]=curr;
		curr++;
	}
	for(int i =0;i<n;i++){
		cout << no[adj[i]] << " ";
	}cout <<  endl;
}

int main(){
	// int t;
	// cin >> t;
	// while(t--)
		solve();
}