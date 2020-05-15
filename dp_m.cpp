#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e5 +5;

const int modi = 1e9+7;

void add_mod(int& a, int b){
	a+=b;
	if(a>=modi)
		a-=modi;
}


void sub_mod(int &a, int b){
	a-=b;
	if(a<0)
		a+=modi;
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++)
		cin >> a[i];
	int dp[k+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i =0;i<n;i++){
		vector<int> toincrease(k+1,0);
		for(int given = k;given>=0;given--){
			int start = given+1;
			int end = given+min(a[i],k-given);
			if(start<=end){
				add_mod(toincrease[start],dp[given]);
				if(end<k)
					sub_mod(toincrease[end+1],dp[given]);
			}	
			// for(int to_give = 1;to_give<= min(a[i],k-given);to_give++){
			// 	add_mod(dp[given+to_give],dp[given]);
			// }
		}
		int to_add = 0;
		for(int i =1;i<=k;i++){
			add_mod(to_add,toincrease[i]);
			add_mod(dp[i],to_add);
		}	

	}
	// for(int i =0;i<=k;i++)
	// 	cerr<< dp[i] << " ";
	cout << dp[k] << endl;
}