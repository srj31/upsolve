#include<bits/stdc++.h>
using namespace std;

int main(){
	cerr << "works123" << endl;
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int dp[k+1];
	dp[0] = 0;
	int i = 1;
	while(i<a[0]){
		dp[i] = 0;
		i++;
	}

	for(int i=a[0];i<=k;i++){
		dp[i] = 0;
		for(int j =0;j<n;j++){
			if((i-a[j]>=0) && !dp[i-a[j]])
				dp[i]|=1;
		}
	}
	cout << (dp[k]?"First":"Second") << endl;

}