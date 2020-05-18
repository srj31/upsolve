#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin >> t;
	int mxn = 5e5+1;
	long long int dp[mxn];
	dp[1] = 0;
	for(long long int i =3;i<mxn;i+=2){
		dp[i] = dp[i-2] + 4LL*(i-1)*(i/2);
	}
	while(t--){
		int n ;
		cin >> n;
		cout << dp[n] << endl;
	}
}