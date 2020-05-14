#include<bits/stdc++.h>
using namespace std;
long long int dp2[201][201]; // no of ways of coloring ith ball with color j;
long long int dp[201][201][201];

int main(){	
// cerr << 1 << endl;
// cout << 1 << endl;
	int t;
	cin >> t;
	while(t--){
		int n ;
		cin >> n;
		int c[n];
		int total = 0;
		for(int i =0;i<n;i++){
			cin >> c[i];
			total+=c[i];
		}
		
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));

		dp[0][0][0] = 1;
		// for(int i =0;i<n;i++){
		// 	dp[c[i]][i+1][c[i]] = 1;
		// }
		for(int i =0;i<n;i++){
			dp2[1][i+1][1] = 1;
			dp2[1][i+1][0] = 1;
		}
		long long int modi  = 1e9+7;
		long long int before = n;
		// i - pos of ball    j - color of the ball at i       k -  kth ball of that color
		for(int i =2 ;i<=total;i++){
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=c[j-1];k++){
					dp[i][j][k] += (before - dp2[i-1][j][k-1]+modi)%modi;
					dp[i][j][k]%=modi;
					dp2[i-1][j] += dp[i][j][k];
					dp2[i-1][j]%=modi;
					cout << dp[i][j][k] << " " << i << " " << j<< " " << k << endl; 
				}
			}
			before = 0;
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=c[j-1];k++){
					before+=dp[i][j][k];
					before%=modi;
					dp2[i][j] += dp[i][j][k];
					dp2[i][j]%=modi;
				}
				cout << dp2[i][j] << " " << i << " " << j << endl;
			}
			cout << before << " before "<< endl;

		}
		long long int ans = 0;
		for(int i =0;i<n;i++){
			ans+= dp[n][i+1][c[i]];
			ans%=modi;
		}
		cout << ans << endl;
	}
}