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
	int r,c;
	cin >> r >> c;
	string a[r];
	for(int i =0;i<r;i++){
		cin >> a[i];
	}
	int flaga = 0;
	for(int i=0;i<r;i++){
		for(int j =0;j<c;j++){
			if(a[i][j]=='A')
			{
				flaga=1;
				break;
			}
		}
		if(flaga)break;
	}
	if(!flaga){
		cout << "MORTAL" << endl;return;
	}

	int ans = 4;
	//check for all rows or columns;
	string colfull ="",rowfull="";
	for(int i =0;i<c;i++){
		rowfull+='A';
	}
	for(int i =0;i<r;i++){
		colfull+='A';
	}

	for(int i =0;i<r;i++){
		if(a[i]==rowfull){
			if(i==0 || i==r-1){
				ans = 1;break;
			}
			else{
				ans=min(ans,2);
			}
		}
	}
	for(int j =0;j<c;j++){
		string currcol = "";
		for(int i =0;i<r;i++){
			currcol+=a[i][j];
		}
		if(currcol==colfull){
			if(j==0 || j==c-1){
				ans = 1;break;
			}
			else
				ans =min(ans,2);
		}
	}
	for(int i =1;i<c-1;i++){
		if(a[0][i]=='A' || a[r-1][i]=='A'){
			ans=min(ans,3);break;
		}
	}
	for(int j =1;j<r-1;j++){
		if(a[j][0]=='A' || a[j][c-1]=='A'){
			ans = min(ans,3);break;
		}
	}

	if(a[0][0]=='A' || a[0][c-1]=='A' || a[r-1][0]=='A' || a[r-1][c-1]=='A')
		ans = min(ans,2);

	int flagall = 1;
	for(int i =0;i<r;i++){
		for(int j=0;j<c;j++){
			if(a[i][j]!='A')
			{
				flagall=0;break;
			}
		}
		if(!flagall)break;
	}

	if(flagall)
		ans = 0;

	cout << ans << endl;

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int t;cin >> t;while(t--)
		solve();
}