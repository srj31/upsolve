#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n , k;
		cin >> n >> k;
		string lamps;
		cin >> lamps;
		int dp[n+1][3];
		dp[0][0] = dp[0][1]  = 0;
		// dp[i][j]  -> best answer for i if the j==0 all are off j == 1 on ones are at k distance
		for(int i =1;i<=k;i++){
			dp[i][0] = lamps[i-1]=='1';
			dp[i][0]+=dp[i-1][0];
			dp[i][1] = lamps[i-1]=='0';
			dp[i][1] += dp[i-1][0];
			// dp[i][2] = lamps[i-1]=='1' + min(dp[i][0],dp[i][1]);
		}
		for(int i =k+1;i<=n;i++){
			dp[i][0] = lamps[i-1]=='1';
			dp[i][0] +=dp[i-1][0];
			dp[i][1] = lamps[i-1]=='0';
			dp[i][1] += min(dp[i-1][0],dp[i-k][1]+dp[i-1][0]-dp[i-k][0]);
			// dp[i][2]  = lamps[i-1]=='1' + dp[i-1][2];
 		}

 		int ans = 1e9;
 		for(int i=1;i<=n;i++){
 			ans = min(ans,dp[i][1] + dp[n][0]-dp[i][0]);
 		}
 		ans = min(ans,dp[n][0]);
 		cout << ans  << endl;
	}
}