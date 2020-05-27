#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	int task = 1;
	while(task<=t){
		int r,c;
		cin >> r >> c;
		string poly[r];
		set<int> chars;
		for(int i =0;i<r;i++){
			cin >> (poly[i]);
			for(int j =0;j<c;j++){
				poly[i][j]-='a';
				chars.insert(poly[i][j]);
			}
		}
		int n  = chars.size();
		string ans = "";
		int good[r][c];
		memset(good,0,sizeof(good));
		for(int i =0;i<n;i++){
			int none = 1;
			for(auto e:chars){
				int dp[r][c];
				int bad=0;
				memcpy(dp,good,sizeof(dp));
				for(int x =r-1;x>=0;x--){
					for(int y = 0;y<c;y++){
						if(x==r-1){
							if(poly[x][y]==e)
								dp[x][y] = 1;
						}
						else{
							if(poly[x][y]==e){
								if(dp[x+1][y]==1)
									dp[x][y] = 1;
								else{
									// cerr << char(e+'a') << " " << x << " " << y << endl;
									bad =1; 
									break;
								}
							}
						}
					}
					if(bad) break;
				}
				if(!bad){
					memcpy(good,dp,sizeof(good));
					ans+=char(e+'a');
					chars.erase(e);
					none = 0;
					break;
				}
			}
			if(none){
				ans = "-1";break;
			}
		}
		cout << "Case #" << task << ": " << ans << endl;
		task++;
		
	}
}