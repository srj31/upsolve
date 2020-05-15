#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long int  a[n];
	long long int pref[n+1];
	pref[0] = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
		pref[i+1] = pref[i] + a[i];
	}

	long long int dp[n][n];
	memset(dp,0x3f,sizeof(dp));
	for(int i =0;i<n;i++){
		dp[i][i] = 0;
	}

	for(int l = 2;l<=n;l++){
		for(int i = 0;i<n-l+1;i++){
			int j = i+l-1;
			for(int k = i;k<j;k++){
				dp[i][j] = min(dp[i][j],(dp[i][k]+dp[k+1][j])+(pref[k+1]-pref[i] + pref[j+1]-pref[k+1]));
			}
		}
	}

	// for(int i =0;i<n;i++){
	// 	for(int j = 0;j<n;j++){
	// 		cout << dp[i][j] << " ";
	// 	}cout << endl;
	// }
	cout << dp[0][n-1] << endl;
}