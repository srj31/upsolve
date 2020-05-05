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
	int n;
	cin >> n;
	string s,t;
	cin >> s >> t;
	//need to find the total number of inversions in both the strings.

	string cs,ct;
	cs = s;ct = t;
	sort(cs.begin(),cs.end());
	sort(ct.begin(),ct.end());
	int pos = 0;
	if(cs!=ct){
		pos|=0;
		cout << "NO" << endl;return;
	}
	//if there is a char which occurs twice
	map<int,int> count;
	for(int i =0;i<n;i++){
		count[s[i]-'a']++;
		if(count[s[i]-'a']>1)
			pos|=1;

	}
		if(pos){cout << "YES" << endl;return;}

	map<int,int> poss,post;
	for(int i =0;i<n;i++){
		poss[s[i]-'a'] = i;
		poss[t[i]-'a'] = i;
	}

	int pars=0,part=0;
	for(int i =0;i<n;i++){
		for(int j =0;j<n-1-i;j++){
			if(s[j]>s[j+1])
			{
				swap(s[j],s[j+1]);
				pars++;
			}
		}
	}
	for(int i =0;i<n;i++){
		for(int j =0;j<n-1-i;j++){
			if(t[j]>t[j+1])
			{
				swap(t[j],t[j+1]);
				part++;
			}
		}
	}	

	if(pars%2==part%2){
		pos|=1;
	}	

	cout << (pos?"YES":"NO") << endl;
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int t;cin >> t;while(t--)
		solve();
}