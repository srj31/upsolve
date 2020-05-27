#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
bool cmp(pair<long long int ,long long int  > a , pair<long long int ,long long int  > b){
	return a.x > b.x || ((a.x == b.x )&&(a.y>b.y));
}

int main(){
	long long int  n,m,v,p;
	cin >> n >> m >> v >> p;
	long long int  a[n];
	for(long long int  i =0;i<n;i++){
		cin >> a[i];
	}
	long long int  ans = 0;
	sort(a,a+n);
	reverse(a,a+n);	
	auto ok = [&](long long int  mid){
		if(mid<p) return true;
		if(a[mid]+m<a[p-1]) return false;

		long long int tot = 0;
		
		for(int i =n-1;i>=mid;i--)
			tot+=m;
		for(int i =0;i<p-1;i++)
			tot+=m;

		for(int i = p-1;i<mid;i++)
			tot+=(m+a[mid]-a[i]);

		return tot>=m*v;
	};

	long long int  lo = 0,hi = n-1;
	while(lo<=hi){
		long long int  mi = (lo+hi)/2;
		if(ok(mi))lo=mi+1;
		else hi = mi-1;
	}
	ans = hi+1;
	cout << ans << endl;
}