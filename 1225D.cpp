#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,k;
ll ans;
map<vi, vector<vector<int> > > primes_deg;
void factor(int a,vi &p , vi &deg){
	
	for(int i=2;i*i<=a;i++){
		int count = 0;
		while(a%i==0){
			count++;
			a/=i;
		}
		if(count%k){
			p.pb(i);
			deg.pb(count%k);
		}

	}
	if(a>1){
		p.pb(a);deg.pb(1);
	}
}

void find(vector<vector<int> >deg){
	int l = deg[0].size(); // how many primes 
	map<vi,int> cnt;
	for(auto e:deg){
		cnt[e]++;
	}

	ll div2= 0;//which are counted twice

	for(auto e:cnt){
		vi v1(l);
		for(int i =0;i<l;i++){
			v1[i] = k-e.first[i];
		}

		if(v1 == e.first){
			ans+= (ll)e.second*(ll)(e.second-1)/2;
		}
		else{
			div2+=e.second*1LL*cnt[v1];
		}
	}
	ans+=div2/2;
}

void solve(){
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	for(int i =0;i<n;i++){
		vi p,deg;
		factor(a[i],p,deg);
		primes_deg[p].push_back(deg);
	}

	for(auto e:primes_deg){
		find(e.second);
	}
	cout << ans << endl;
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