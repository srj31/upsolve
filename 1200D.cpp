#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	string s[n];
	for(int i =0;i<n;i++){
		cin >> s[i];
	}
	int dp1[n+1][n+1][2]; // 1 - > left 2-> right 3-> up 4->down
	int dp2[n+1][n+1][2];
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			dp1[i][j][0] = dp1[i-1][j][0];
			dp1[i][j][1] = dp1[i][j-1][1];
			if(s[i-1][j-1]=='W'){
				dp1[i][j][0] += dp1[i][j-1][0] - dp1[i-1][j-1][0];
				dp1[i][j][1] += dp1[i-1][j][1] - dp1[i-1][j-1][1];
			}
		}
	}

	for(int i =n-1;~i;i--){
		for(int j=n-1;~j;j--){
			dp2[i][j][0] = dp2[i+1][j][0];
			dp2[i][j][1] = dp2[i][j+1][1];
			if(s[i][j]=='W'){
				dp2[i][j][0] += dp2[i][j+1][0] - dp2[i+1][j+1][0];
				dp2[i][j][1] += dp2[i+1][j][1] - dp2[i+1][j+1][1];
			}
		}
	}

	int ans = 0;
	for(int i =0;i<n-k+1;i++){
		for(int j = 0;j<n-k+1;j++){
			int curr = 0;
			curr += dp1[n][j][1];
			curr+= dp1[i][n][0];
			curr+ dp2[i+k][0][0] + dp2[0][j+k][1];
			
		}
	}


}