#include<bits/stdc++.h>
using namespace std;

class SuffixDecomposition{
	public:


		const int modi = 1812447359;
		
		void add_mod(long long &a, long long b){
			a+=b;

		}
		long long findTotalFun(vector <int> P, int A0, int X, int Y, int B0, int X1, int Y1, int N){
			long long A[N];
			A[0] = A0;
			for(int i =1;i<N;i++)
				A[i] = (A[i-1]*X%modi)*Y%modi;

			long long  B[N];
			B[0] = B0;
			for(int i =1;i<N;i++)
				B[i] = (B[i-1]*X1%modi)*Y1%modi;

			vector<int>S = P;
			for(int i =P.size();i<N;i++){
				S.push_back(max(A[i],B[i]));
			}
			// int n = N;
			long long dp[N+1];
			memset(dp,0,sizeof(dp));
			stack<pair<int,int> > nextbig;
			dp[N] = 1;
			nextbig.push(make_pair(S[N-1],N));
			for(int i = N-2;i>=0;i--){
				if(S[i]<S[i+1]){
					add_mod(dp[i+1],dp[i+2]+1);
					nextbig.push(make_pair(S[i],i+1));
				}
				else{
					int pos = -1;
					while(!nextbig.empty()&&nextbig.top().first<S[i]){
						nextbig.pop();
					}
					if(nextbig.empty()){
						dp[i+1] = 1;
					}
					else{
						pos = nextbig.top().second;
						add_mod(dp[i+1],dp[pos]+1);
					}

					nextbig.push(make_pair(S[i],i+1));
				}
			}
			long long ans = 0;
			for(int i =0;i<N;i++){
				ans+=dp[i+1];
			}
			return ans;
		}
		
};