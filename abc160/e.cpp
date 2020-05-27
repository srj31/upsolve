#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int x,y,a,b,c;
	cin >> x >> y >> a >> b >> c;
	// long long int ans[x+y+1];
	// ans[0] = 0;
	long long int re[a],g[b],cl[c];
	for(long long int i =0;i<a;i++)
		cin >> re[i];
	for(long long int i =0;i<b;i++)
		cin >> g[i];
	for(long long int i =0;i<c;i++)
		cin >> cl[i];
	sort(re,re+a,greater<long long int>());
	sort(g,g+b,greater<long long int>());
	sort(cl,cl+c,greater<long long int>());
	vector<long long int> ans;
	for(int i =0;i<x;i++)
		ans.push_back(re[i]);

	for(int i =0;i<y;i++)
		ans.push_back(g[i]);

	for(int i =0;i<min(c,x+y);i++)
		ans.push_back(cl[i]);

	sort(ans.begin(),ans.end(),greater<long long int>());

	long long int res = 0;
	for(int i = 0;i<x+y;i++)
		res+=ans[i];

	cout << res << endl;
}