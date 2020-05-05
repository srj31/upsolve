#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mxN = 2e5+99;
int n;
int a[mxN];

vector<int> val(mxN,mxN);
vector<int> adj[mxN];
int vis[mxN];
void dfs(int u){
	// cout << u+1 << " u" << endl; 
	int cango = 0;
	vis[u]=1;
	random_shuffle(adj[u].begin(),adj[u].end());
	for(auto v:adj[u]){
		if(!vis[v])
			dfs(v);
		val[v] = min(val[v],val[u]+1);
	}
	
}
void solve(){
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	vector<int> start;
	for(int i =0;i<n;i++){
		// cout << i << endl;
		if(i-a[i]>=0){
			// cout << i-a[i] << endl;
			adj[i-a[i]].pb(i);
			if(a[i-a[i]]%2!=a[i]%2){
				val[i] = 1;
			}
		}

		if(i+a[i]<n){
			// cout << i+a[i] << endl;

			adj[i+a[i]].pb(i);
			if(a[i+a[i]]%2!=a[i]%2){
				val[i] = 1;
				// start.pb(i);
			}
		}
		if(val[i]==1){
			start.pb(i);
		}
	}
	// cout << 1 << endl;

	for(auto e:start){
		// cout << e << endl;
		dfs(e);
	}

	// for(int i =0;i<n;i++){
	// 	dfs(i);
	// }
	for(int i =n-1;~i;i--)dfs(i);

	for(int i =0;i<n;i++){
		if(val[i]==mxN)
			val[i] = -1;
		cout << val[i] << " ";
	}cout << endl;
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}