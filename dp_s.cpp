#include<bits/stdc++.h>
using namespace std;
int d;

int binpow(int a, int b){
	int res = 1;
	while(b)
	{
		if(b%2==1)
			res = res*a%d;
		a=a*a%d;
		b>>=1;
	}
	return res;
}


int main(){
	string k;
	cin >> k >> d;
	int n =k.length();
	long long int dp[d];
	for(int i =0;i<d;i++)
		dp[i]=0;
	
	for(int i =1;i<=9;i++){
		dp[i%d]++;
	}
	for(int i =n-2;i>0;i--){
		for(int j = 1;j<=9;j++){
			long long inc = j*binpow(10,n-1-i)%d;
			cout << inc << " " << i << "  " << j << endl;
			for(int x = 0;x<d;x++){
				dp[(x+inc)%d] += dp[x];
			}
		}
	}
	cout << dp[0] << endl;
	for(int i = 1;i<=k[0]-'0';i++){
		long long inc = i*binpow(10,n-1)%d;
			cout << inc << " " << i << endl;
			for(int x = 0;x<d;x++){
				dp[(x+inc)%d] += dp[x];
			}
	}
	cout << dp[0] << endl;
}