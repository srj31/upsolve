class EllysNimDiv2
{
	const int mxn = 1e9;
public:
	int getMin(vector <int> A){
		int n =A.size();
		long long int dp[n+1][2048];
		memset(dp,mxn,sizeof(dp));
		dp[1][A[0]] = 0;
		for(int i = A[0];i<2048;i++){
			dp[1][i] = i - A[0];
		}

		for(int i =2;i<=n;i++){
			for(int j =0;j<2048;j++){
				for(int k =0;k<1024;k++){
					dp[i][j^(a[i-1] + k)] = min(dp[i][j^(a[i-1]+k)],dp[i-1][j]+k);
				}
			}
		}
		return dp[n][0];
	}
};
