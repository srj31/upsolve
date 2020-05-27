#include<bits/stdc++.h>
using namespace std;

struct pt{
	long long x,y;

	bool operator < (pt b) const{
		return x < b.x || (x==b.x && y<b.y);
	}

	long long operator &(pt b) const{
		return x*b.y - y*b.x;
	}

	long long operator *(pt b)const{
		return x*b.x + y*b.y;
	}
	pt operator -(pt b) const{
		pt res;
		res.x = x-b.x;
		res.y = y-b.y;
		return res;
	}
 };

long long ccw(pt a, pt b, pt c){
	return ((b-a)&(c-a));
}

vector<pt> hull(vector<pt> pts){
	int n = pts.size();
	vector<pt> h;
	if(n==1){
		h.push_back(pts[0]);
	// cerr << "HULL DONE" << endl;

		return h;
	}

	pt p1 = pts[0];
	pt p2 = pts[n-1];
	vector<pt> up,down;
	up.push_back(p1);
	down.push_back(p1);
	for(int i =1;i<n;i++){
		if(i==n-1 || ccw(p1,pts[i],p2)<0){
			while(up.size()>=2 && ccw(up[up.size()-2],up[up.size()-1],pts[i])>=0)
				up.pop_back();
			up.push_back(pts[i]);
		}
		if(i==n-1 || ccw(p1,pts[i],p2)>0){
			while(down.size()>=2 && ccw(down[down.size()-2],down[down.size()-1],pts[i])<=0)
				down.pop_back();
			down.push_back(pts[i]);
		}
	}
	for(int i =0;i<up.size();i++)
		h.push_back(up[i]);
	for(int i = down.size()-2;i>0;i--){
		h.push_back(down[i]);
	}
	// cerr << "HULL DONE" << endl;
	return h;
}

long long dist2(pt a, pt b){
	return (b-a)*(b-a);
}

long long dia(vector<pt>h){
	int n = h.size();
	if(n==1)
		return 0;
	if(n==2){
		return dist2(h[0],h[1]);
	}

	int k = 1;
	while(abs(ccw(h[n-1],h[0],h[(k+1)%n]))>abs(ccw(h[n-1],h[0],h[k])))
		k++;

	long long res  = 0;
	for(int i =0,j=k;i<=k && j<n;i++){
		res = max(res, dist2(h[i],h[j]));
		while(j<n && abs(ccw(h[i],h[(i+1)%n],h[(j+1)%n]))>abs(ccw(h[i],h[(i+1)%n],h[(j)%n]))){
			res = max(res,dist2(h[i],h[(j+1)%n]));
			j++;
		}
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pt> pts(n);
		for(int i =0;i<n;i++){
			cin >> pts[i].x >> pts[i].y;
		}
		sort(pts.begin(),pts.end());
		vector<pt> ch = hull(pts);
		long long ans = dia(ch);
		cout << ans << endl;
	}
}