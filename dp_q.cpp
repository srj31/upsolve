#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int h[n],a[n];
	for(int i =0;i<n;i++){
		cin >> h[i];
	}	
	for(int i = 0;i<n;i++)
		cin >> a[i];

	int base = 1;
	while(base<=n)
		base<<=1;
	vector<long long> t(2*base,0); // creating a perfect binary tree and will only ask queries from base+0 to base+n

	long long dp[n+1];//the max possible beauty  if the last taken height is i
	memset(dp,0,sizeof(dp));
	for(int i =0;i<n;i++){
		int l = 0;
		int r = base + h[i]; // the right bound .. finding the max vlue from [0,h)
		long long best = 0;
		for(l+=base;l<r;l>>=1,r>>=1){
			if(l&1)
				best = max(best, t[l++]);
			if(r&1)
				best = max(best,t[--r]);
			// cout << l << " l r " << r << endl;
		}
		dp[h[i]] = best + a[i];

		for(int j = h[i]+base;j>=1;j>>=1){
			t[j] = max(t[j],dp[h[i]]);
		}
		// cout << dp[h[i]] << " " << h[i] << " " << endl;
	}
	long long ans = 0;
	for(int i =0;i<=n;i++){
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
}