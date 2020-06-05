#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cin >> n >> m;
	int dp[n][m+1];
	vector<pair<int,int > >sats(n);
	for(int i =0;i<n;i++){
		cin >> sats[i].first >> sats[i].second;
	}
	sort(sats.begin(),sats.end());

	int start = sats[0].first;
	int s = sats[0].second;
	dp[0][1] = max((start-s)-i,0);
	for(int i =2;i<=start+s;i++){
		dp[0][i] = dp[0][1];
	}
	for(int i = start+s+1;i<m;i++){
		dp[0][i] = dp[0][i-1];
		if(i-start>s)
			dp[0][i]++;
	}

	for(int i =1;i<n;i++){
		int pos = sats[i].first;
		int spos = sats[i].second;
		dp[i][1] = min(dp[i-1][1],max((pos-s)-i),0);
		for(int j = 2;j<=max(pos-spos,0);j++){
			int togo = max((pos-spos)-j,0);
			dp[i][j] = min(dp[i-1][j],)
		}
	}
}