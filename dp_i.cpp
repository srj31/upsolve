#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	double probs[n];
	for(int i =0;i<n;i++)
		cin >> probs[i];
	double dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1.0;
	for(int i =1;i<=n;i++){
		dp[0][i] = 0.0;
	}

	for(int i =1;i<=n;i++){
		for(int j =0;j<=i-1;j++){
			dp[i][j+1]+= dp[i-1][j] * probs[i-1];
			dp[i][j] += dp[i-1][j]*(1-probs[i-1]);
		}
	}
	double ans = 0.0;
	for(int i = 1;i<=n;i++){
		if(i>n/2)
			ans+=dp[n][i];
	}
	cout <<fixed << setprecision(12) <<  ans << endl;
}