#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int a[n],b[n];
		for(int i =0;i<n;i++)
			cin >> a[i];
		for(int i =0;i<n;i++)
			cin >> b[i];

		sort(a,a+n);
		sort(b,b+n);
		int aidx = 0;
		int bidx = n-1;
		int count = 0;
		while(k--){
			if(a[aidx]<b[bidx]){
				swap(a[aidx],b[bidx]);
				aidx++;
				count++;
				sort(b,b+n);
			}
			
		}
		int ans =0 ;
		for(int i =0;i<n;i++){
			ans+=a[i];
		}
		cout << ans << endl;
	}
}