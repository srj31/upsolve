#include<bits/stdc++.h>
using namespace std;

int dig[10] = {6,2,5,5,4,5,6,3,7,6};

int main(){
	ifstream cin("auxiliary.in","r",stdin);
	freopen("auxiliary.out","w",stdin);

	int n;
	fin >> n;
	const int mxn = 1e6+10;
	long long int dp[mxn];
	memset(dp,-1,sizeof(dp));
	dp[2] = 1;
	dp[3] = 7;
	dp[4] = 4;
	dp[5] = 8;
	dp[6] = 14;
	dp[7] = 11;
	dp[8] = 15;
	dp[9] = 21;
	for(int i =10;i<=n;i++){
		for(int j = 0;j<10;j++){
			int need = dig[j];
			if(dp[i-need]!=-1){
				dp[i] = max(dp[i],dp[i-need]+j);
			}
		}
	}

	fout << (dp[n]==-1?0:dp[n]) << endl;

}