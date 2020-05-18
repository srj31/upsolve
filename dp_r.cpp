#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
typedef vector<vector<long long int> > vvi;

vvi mul(vvi a, vvi b){
	int n = a.size();
	vvi c(n,vector<long long int>(n));
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			for(int k =0;k<n;k++){
				c[i][j]+= (a[i][k]*b[k][j])%mod;
				c[i][j]%=mod;
			}
		}
	}
	return c;
}

int main(){

	long long int n,k;
	cin >> n >> k;
	vvi g(n,vector<long long int>(n));
	vvi ans(n,vector<long long int>(n));
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			cin >> g[i][j];
			ans[i][j]  = g[i][j];
		}
	}

	
	k--;
	while(k){
		if(k&1){
			ans = mul(ans,g);
		}
		g = mul(g,g);
		k>>=1;
	}

	long long res = 0;
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			res+=ans[i][j];
			// cout << ans[i][j] << " ";
			res%=mod;
		}
	}
	cout << res << endl;

}