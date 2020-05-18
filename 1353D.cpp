#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> ans(n+1,0);
		priority_queue<pair<int,pair<int,int> > > q;
		q.push(make_pair(n,make_pair(-1,-n)));
		int val = 1;
		while(!q.empty()){
			auto range = q.top();
			q.pop();
			int l = -range.second.first;
			int r = -range.second.second;
			int m = (l+r)/2;
			ans[m] = val;
			val++;
			int d1 = (m-l);
			int d2 = (r-m);
			if(d1!=0)
				q.push(make_pair(d1,make_pair(-l,-(m-1))));
			if(d2!=0)
				q.push(make_pair(d2,make_pair(-(m+1),-r)));
		}
		for(int i = 1;i<=n;i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}