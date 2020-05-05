#include<bits/stdc++.h>
using namespace std;

struct pts{
	int x,y,z,idx;
};

bool comp(pts a, pts b){
	if(a.x<b.x){
		return a.x < b.x;
	}
	if(a.x == b.x){
		return a.y < b.y ||((a.y==b.y) &&(a.z<b.z) );
	}
	return a.x < b.x;
}

void solve(){
	int n;
	cin >> n;
	vector<pts> pt(n);
	for(int i =0;i<n;i++){
		cin >> pt[i].x >> pt[i].y >> pt[i].z;
		pt[i].idx = i+1;
	}
	sort(pt.begin(),pt.end(),comp);
	for(int i =0;i<n;i+=2){
		cout << pt[i].idx << " " << pt[i+1].idx << endl;
	}
}

int main(){
	// int t;
	// cin >> t;
	// while(t--)
		solve();
}