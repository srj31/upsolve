#include<bits/stdc++.h>
using namespace std;

int modi = 1e9+7;

int main(){
	int h,w;
	cin >> h >> w;
	string g[h];
	for(int i =0;i<h;i++)
		cin >> g[i];

	long long int dp[h+1][w+1];
	for(int i =0;i<=h;i++)
		dp[i][0] = 0;
	for(int i =0;i<=w;i++)
		dp[0][i] = 0;
	dp[0][1] = 1;
	dp[1][0] = 1;
	for(int i = 1;i<=h;i++){
		dp[i][1] = (dp[i-1][1] && g[i-1][0]=='.');
	}
	for(int i = 1;i<=w;i++){
		dp[1][i] = dp[1][i-1] && g[0][i-1]=='.';
	}

	for(int i = 2;i<=h;i++){
		for(int j = 2;j<=w;j++){
			dp[i][j] = 0;
			if(g[i-1][j-1]!='#'){
				dp[i][j] += dp[i-1][j] + dp[i][j-1];
				dp[i][j]%=modi;
			}
		}
	}
	cout << dp[h][w] << endl;
}