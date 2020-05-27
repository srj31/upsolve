#include<bits/stdc++.h>
using namespace std;

const int modi = 998244353;

int main(){
	int n,s;
	cin >> n >> s;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	long long  dp[n+1][s+1];
	long long ans = 0;
	memset(dp,0,sizeof(dp));
	for(int i =0;i<n;i++){
		memcpy(dp[i+1],dp[i],sizeof(dp[0]));
		(dp[i+1][a[i]]+=i+1)%=modi;
		for(int j =0;j+a[i]<=s;j++)
			(dp[i+1][j+a[i]]+=dp[i][j])%=modi;
		(ans+=dp[i+1][s])%=modi;
	}
	cout << ans << endl;
}