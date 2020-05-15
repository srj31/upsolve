#include<bits/stdc++.h>
using namespace std;

const int mxn = 3e3 + 5;
long long int dp[mxn][mxn][2]; // the maxi value if there are from i to j elements on player kth turn
	// [0] = maximize the valuse [1]--> minimize the value

int main(){
	int n;
	cin >> n;
	long long int a[n];
	for(int i =0;i<n;i++)
		cin >> a[i];

	for(int i =0;i<=n;i++)
		for(int j =0;j<=n;j++){
			dp[i][j][0] = -1e18;
			dp[i][j][1] = 1e18;
		}
	for(int i =0;i<=n;i++){
		dp[i][i][0] = a[i-1];
		dp[i][i][1] = -a[i-1];
	}

	for(int j =1;j<=n;j++){
		for(int i = j-1;i>0;i--){
			dp[i][j][0] = max(a[i-1]+dp[i+1][j][1],max(a[j-1]+dp[i][j-1][1],dp[i][j][0]));
			dp[i][j][1] = min(dp[i+1][j][0]-a[i-1],min(dp[i][j-1][0] - a[j-1],dp[i][j][1]));

			
		}
		// cout << endl;
	}

	// for(int i=1;i<=n;i++){
	// 	for(int j =1;j<=n;j++){
	// 		cout <<"( "<< dp[i][j][0] << " , " << dp[i][j][1] << ")";
	// 	}
	// 	cout << endl;
	// }

	cout << dp[1][n][0] << endl;
}