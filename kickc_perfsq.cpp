#include<bits/stdc++.h>
using namespace std;
const long long int mxn = 1e5;
long long int cnt[2*100*mxn+10];
int main(){
	long long int t;
	cin >> t;
	long long int task =t;
	set<long long int> squares;
	for(long long int i =0;i*i<1e7;i++)
		squares.insert(i*i);
	while(t--){
		long long int n;
		cin >> n;
		long long int pref[n+1];
		pref[0] = 0;
		long long int mini = 0;
		long long int a[n];
		memset(cnt,0,sizeof(cnt));
		for(int i =0;i<n;i++){
			cin >> a[i];
			mini+=abs(a[i]);
		}
		// long long int a[n];
		cnt[mini]++;
		long long int ans =0;
		for(long long int i = 0;i<n;i++){
			
			pref[i+1] = pref[i]+ a[i];
			for(auto e:squares){
				long long int check = pref[i+1] - e;
				if(check>=0)
					ans+=cnt[check+mini];			
			}
			if(pref[i+1]+mini>=0)
				cnt[pref[i+1]+mini]++;
			// cout << ans << endl;
		}
		cout << "Case #" << task-t << ": " << ans << endl;
	}

}