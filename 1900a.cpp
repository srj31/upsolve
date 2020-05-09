#include<bits/stdc++.h>
using namespace std;

void solve(){
	long long int n,m;
	cin >> n >> m;
	long long int a[n],b[m];
	map<long long int,long long int> count;
	for(long long int i =0;i<n;i++){
		cin >> a[i];
		count[a[i]]++;
	}
	for(long long int i =0;i<m;i++)
		cin >> b[i];
	sort(a,a+n);
	long long int dp[m+1];
	dp[m] = count[m];
	for(long long int i =m-1;i>0;i--){
		dp[i] = dp[i+1];
		dp[i]+=count[i];
		// cout << dp[i] << endl;
	}
	long long int maxisize = 0;
	for(long long int i=1;i<=m;i++){
		long long int curr = (dp[i]+b[i-1]-1)/b[i-1];
		maxisize=max(maxisize,curr);
	}

	vector<vector<long long int> > ans(maxisize);
	for(long long int i =0;i<n;i++){
		ans[i%maxisize].push_back(a[i]);
	}
	cout << maxisize << endl;
	for(long long int i =0;i<maxisize;i++){
		cout << ans[i].size() << " ";
		for(long long int j =0;j<ans[i].size();j++)
			cout << ans[i][j] << " ";
		cout<<endl;
	}

}

int main(){
	// int t;
	// cin >> t;
	// while(t--)
		solve();
}