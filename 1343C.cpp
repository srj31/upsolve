#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i =0;i<n;i++)
			cin >> a[i];

		int dp[n+1][2]; // including it or not
		for(int i =0;i<n+1;i++){
			dp[i][0] = INT_MIN;
			dp[i][1] = INT_MIN;
		}
		for(int i =1;i<=n;i++){
			dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
			dp[i][1] = 
		}

		cout << max(dp[n][0],dp[n][1]) << endl;
	}
}