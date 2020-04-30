#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void solve(){
	int n,m;
	cin >> n >> m;
	int a[n][m];
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cin >> a[i][j];
		}
	}
	int ans =0;
	for(int i =0;i<m;i++){
		set<int> shouldbe;
		for(int j =0;j<n;j++){
			shouldbe.insert(j*(m)+i+1);
		}
		map<int,int> pos; // how much to move 
		int wrong = 0;
		for(int j =0;j<n;j++){
			if(shouldbe.find(a[j][i])!=shouldbe.end()){
				int reqpos = (a[j][i]-(i+1))/m;
				if(reqpos<=j){
					
					pos[j-reqpos]++;
					// if(i==1){
					// 	cout << a[j][i] << " 2 " <<reqpos<<" "<<pos[2] <<  endl;
					// }
				}
				else{
					// if(i==1){
					// 	cout << a[j][i] << " 2 " <<reqpos<< endl;
					// }
					pos[j+(n-reqpos)]++;
				}
			}
			else{
				wrong++;
			}
		}
		int currshift=-1;
		int mincost = n;
		for(auto e:pos){
			if(e.first+(n-e.second)<mincost){
				mincost=e.first+(n-e.second);
				currshift= e.first;
			}
		}	
		ans+=mincost;
	}

	cout << ans << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}