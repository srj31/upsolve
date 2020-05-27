#include<bits/stdc++.h>
using namespace std;


void min_self(int & a, int b){
	if(b<a)
		a=b;
}

int main(){
	int h,w;
	cin >> h >> w;
	string grid[h];
	for(int i =0;i<h;i++)
		cin >> grid[i];

	int dp[h][w];
	dp[0][0] = 0;
	for(int i =0;i<h;i++){
		for(int j = 0;j<w;j++){
			if(i+j==0)
				dp[0][0] = (grid[0][0]=='#');
			else{
				dp[i][j] = INT_MAX;
				if(i>0){ // could have come from the top cell
					min_self(dp[i][j],dp[i-1][j]+(grid[i][j]=='#' && grid[i-1][j]=='.'));
				}
				if(j>0)
					min_self(dp[i][j],dp[i][j-1]+(grid[i][j]=='#' && grid[i][j-1]=='.'));
			}
		}
	} 

	cout << dp[h-1][w-1] << endl;

}