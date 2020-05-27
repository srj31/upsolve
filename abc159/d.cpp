#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n;
	cin >> n;
	long long int a[n];
	map<long long int,long long int> cnt;
	for(int i =0;i<n;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	long long int t = 0;
	for(auto e:cnt){
		t+= e.second*(e.second-1)/2;
	}

	for(int i =0;i<n;i++){
		long long int val = a[i];
		long long int tosub = cnt[val];
		long long int ans = t - (tosub*(tosub-1)/2);
		long long int add = (cnt[val]-1)*(cnt[val]-2)/2;
		ans+=add;
		cout << ans << endl;
	}
		// cout << endl;
}