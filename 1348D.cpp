#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int curr=1;
	int currmass = 1;
	vector<int> ans;
	while(currmass<n){
		if(n-currmass<=2*curr){
			int more = n-currmass;
			ans.push_back(more-curr);break;
		}
		int l =0;
		int r=curr;
		while(l<=r){
			int m = l+(r-l)/2; // m divisions are made
			// cout << m << endl; s
			if(n-(currmass+2*m+(curr-m))>=curr+m){
				l = m+1;
			}else r = m-1;
		}
		// r -- the max divisions done
		// cout << currmass << " " << curr << " " << r << endl;
		// if(r==-1){
		// 	//last day to split;
		// 	int more = n-currmass;
		// 	ans.push_back(more-curr);break;
		// }
		currmass+=2*r + (curr-r);

		curr+=r;
		ans.push_back(r);
	}
	cout << ans.size() << endl;
	for(auto e: ans){
		cout << e << " ";
	}cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
}