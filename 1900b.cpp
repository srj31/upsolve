#include<bits/stdc++.h>
using namespace std;
const int mxN  = 2e5+1;

long long int cnt[4*mxN],xsum[4*mxN];
struct pt{
	int x,v;
};



bool comp(pt a, pt b){
	return a.x < b.x;
}

void update(long long int * tree, int v, int tl, int tr,int idx, long long int val){
	if(tl==tr)
	{
		// cout << v << " " << val << endl;
		tree[v] += val;
		return;
	}
	int m = (tl+tr)>>1;
	if(m<idx){
		update(tree,v<<1|1,m+1,tr,idx,val);
	}
	else{
		update(tree,v<<1,tl,m,idx,val);
	}
	tree[v] = tree[v<<1] + tree[v<<1|1];
}

long long int query(long long int* tree,int v,int tl,int tr,long long int val){
	if(tl>val) return 0;
	if(tr<=val)
		return tree[v];

	int tm = (tl+tr)>>1;
	return query(tree,v<<1,tl,tm,val)+ query(tree,v<<1|1,tm+1,tr,val);
}

void dis(long long int * tree){
	for(int i =0;i<10;i++)
	{
		cout << i << " " << tree[i] << endl;
	}
}

void solve(){
	int n;
	cin >> n;
	vector<pt> pts(n);
	for(int i =0;i<n;i++){
		cin >> pts[i].x;
	}
	vector<int>vs(n);
	for(int i =0;i<n;i++){
		cin >> pts[i].v;
		vs[i] = pts[i].v;
	}
	sort(vs.begin(),vs.end());
	sort(pts.begin(),pts.end(),comp);
	long long int ans = 0;
	for(auto p:pts){
		int vcheck = p.v;
		int vcomp = lower_bound(vs.begin(),vs.end(),vcheck) - vs.begin();
		// cout << vcomp << " vcomp " << ans << endl;
 		ans = ans + query(cnt,1,0,n-1,vcomp)*p.x*1LL - query(xsum,1,0,n-1,vcomp)*1LL;
		update(cnt,1,0,n-1,vcomp,1);
		update(xsum,1,0,n-1,vcomp,p.x);
		// dis(cnt);
		// dis(xsum);
	}
	cout << ans << endl;
}

int main(){
	// int t;
	// cin >> t;
	// while(t--)
		solve();
}