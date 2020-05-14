#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;



int main(){
	int n;
	while(cin >> n){
		int a[n],m[n];
		for(int i =0;i<n;i++){
			cin >> a[i];
			int x = a[i];
			int xd = 0;
			while(x){
				xd |= (1<<(x%10));
				x/=10;
			}
			m[i] = xd;
			// cout << m[i] << endl;
		}
		pair<int,int> dp[101][1024];

		for(int i =0;i<1024;i++)
			dp[0][i] = make_pair(0,0);

		for(int i = 1;i<=n;i++){
			for(int j = 0;j<1024;j++){
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
				if(j&m[i-1]) continue;


				pair<int,int> b = dp[i-1][j];

				b.first+=a[i-1];
				b.second++;
				dp[i][j|m[i-1]] = max(b,dp[i][j]);
				// cout << i << " " << (j|m[i-1]) << endl;
			}

		}
		pair<int,int> maxi = make_pair(0,0);
		for(int i=0;i<1024;i++){
			maxi = max(maxi,dp[n][i]);
		}
		int ans = maxi.second;
		cout << ans << endl;
		dp.clear();
	}
}