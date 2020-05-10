#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){ return b?gcd(b,a%b):a;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int mxn = 1e4+1;
		int dp[n+1][mxn];
		memset(dp,0,sizeof(dp));
		dp[1][a[0]] = 1;
		dp[1][0] = 1;
		dp[0][0] = 1;
		int ans = 0;
		for(int i =2;i<=n;i++){
			for(int j=0;j<=1e4;j++){
				dp[i][j] = dp[i-1][j];
			}
			for(int j=0;j<=1e4;j++){
				dp[i][gcd(j,a[i-1])] += dp[i-1][j];
			}
		}
		ans = dp[n][1];
		cout << ans << endl;
	}
}