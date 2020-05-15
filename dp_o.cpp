#include<bits/stdc++.h>
using namespace std;



// long long int cnt = 0;
int comp[21][21];
int n;
// map<pair<int,set<int> , int > dp;

// void solve(int curr_man,set<int>&taken){
// 	if(curr_man==n)
// 	{
// 		if(taken.size()==n)
// 		cnt++;
// 		return;
// 	}

// 	for(int i =0;i<n;i++){
// 		if(comp[curr_man][i]==1 && taken.find(i)==taken.end()){
// 			taken.insert(i);
// 			solve(curr_man+1,taken);
// 			taken.erase(i);
// 		}
// 	}
// }
const int modi = 1e9 + 7;

void add_mod(int& a,int b){
	a+=b;
	if(a>=modi)
		a-=modi;
}
int dp[22][(1<<21)]; // number of ways such that n men are considered and the relationhsips are in bitsets
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++)
			cin >> comp[i][j];
	}
	int maxi = (1<<n) - 1;

	dp[0][0] = 1;
	for(int i = 1;i<=n;i++){
		for(int j =0;j<=maxi;j++){
			int taken = __builtin_popcount(j);
			if(taken<i-1)
				continue;
			for(int k = 0;k<n;k++){
				if(comp[i-1][k]){
					int wmn = (1<<(k));
					if((wmn&j) == 0){
						add_mod(dp[i][wmn|j],dp[i-1][j]);
					}
				}
			}
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	cout << dp[n][maxi] << endl;
}