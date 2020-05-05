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

vector<char>values;


void solve(){
	int r,c,k;
	cin >> r >> c>> k;
	vector<string> pre;
	int totalrice= 0 ;
	vector<string> ans(r);
	for(int i =0;i<r;i++){
		string s;
		cin >> s;
		pre.pb(s);
		forn(j,0,c){
			if(s[j]=='R')
				totalrice++;
		}

	}

	int mini = totalrice/k;
	int more = totalrice%k;
	int less = k-more;
	int curr=0;
	int idx = 0;
	for(int i =0;i<r;i++){
		string s = pre[i];
		string toadd="";int j,b,ch;
		if(i&1){j=c-1;b=-1,ch=-1;}
		else{
			j=0,b=c,ch=1;
		}
		for(;j!=b;j+=ch){
			// cout << less << " " << more << " " << curr << " " << idx << endl;
			

			if(s[j]=='R'){
				if(less>0){
					if(curr==mini){
						curr=0;
						idx++;
						less--;
					}
				}
				else if(more>0){
					if(curr==mini+1){
						idx++;
						curr=0;
						more--;
					}
				}
				curr++;
			}
			if(i&1){
				toadd = values[idx]+toadd;
			}
			else
				toadd+=values[idx];
		}
		ans[i]=toadd;
	}

	forn(i,0,r){
		cout<< ans[i] << endl;
	}
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	for(int i ='0';i<='z';i++){
		if((i>='0'&&i<='9')||(i>='a'&&i<='z')||(i<='Z'&&i>='A')){
			values.pb(i);
			// cout << i << endl;
		}
	}	

	int t;cin >> t;while(t--)
		solve();
}