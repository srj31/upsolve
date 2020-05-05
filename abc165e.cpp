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


void solve(){
	int n,m;
	cin >> n >> m;
	if(n&1)
	for(int i =0;i<m;i++){
		cout << i+1 << " " << (n-i) << endl;
	}
	else{
		for(int i =0;i<m-1;i++){
			cout << i+1 << " " << (n-i) << endl;
		}
		if(n!=4)
			cout << m << " " << m+2 << endl;
		else{
			cout << m << " " << m+1 << endl;
		}
	}
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