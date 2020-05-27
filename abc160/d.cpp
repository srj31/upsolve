#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x,y;
	cin >> n >> x >> y;
	--x,--y;
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int i =0;i<n;i++){
		dp[i][i] = 0;
		if(i!=n-1)
			dp[i][i+1] = 1;
	}
	for(int i =0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
			dp[i][j] = dp[i][j-1] + 1;
		}
	}

	dp[x][y] = 1;
	for(int i =x+1;i<y;i++){
		dp[x][i] = min(dp[x][i],dp[i][y]+1);
		dp[i][y] = min(dp[i][y],1+dp[x][i]);
	}

	for(int i =0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
			dp[i][j] = min(dp[i][j],min(dp[min(i,x)][max(i,x)]+dp[min(x,j)][max(j,x)],dp[min(i,y)][max(i,y)] + dp[min(y,j)][max(y,j)]));
		}
	}
	int ans[n];
	memset(ans,0,sizeof(ans));
	for(int i =0;i<n;i++){
		for(int j =i+1;j<n;j++){
			ans[dp[i][j]-1]++;
		}
	}

	for(int i =0;i<n-1;i++){
		cout << ans[i] << endl;
	}

}