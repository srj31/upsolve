#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[26];
	for(int i =0;i<26;i++)
		cin>> a[i];

	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i =0;i<=n;i++){
		dp[i][i] = 1;
	}

	for(int i = 2;i<=n;i++){
		for(int j = i-1;j>0;j--){
			
		}
	}
}