#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5;

vector<vector<int> > adjone(mxN);

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i =0;i<n;i++){
		int u,v;
		cin >> u >> v;
		--u,--v;
		adjone[u].push_back(v);
		adjone[v].push_back(u);
	}
	long long total = n*1LL*(n-1)/2;
	long long zpaths = total - m;
}

int main(){
	// int t;
	// cin >> t;
	// while(t--)
		solve();
}