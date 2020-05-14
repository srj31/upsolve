#include<bits/stdc++.h>
using namespace std;

map<int,long long int> A,B;

int main(){
	int n,k;
	cin >> n >> k;
	// map<int,vector<int> > pos;
	int a[n];
	for(int i =0;i<n;i++)
		cin >> a[i];
	
	// memset(dp,0,sizeof(dp));
	long long int ans = 0;
	for(int i =0;i<n;i++){
		if(a[i]%k*k == 0) ans+=B[a[i]/k];
		if(a[i]%k==0) B[a[i]]+= A[a[i]/k];

		A[a[i]]++;
	}
	cout << ans << endl;
}