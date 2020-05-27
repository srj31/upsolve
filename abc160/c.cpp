#include<bits/stdc++.h>
using namespace std;

int main(){
	int k,n;
	cin >> k >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int sum = 0;
	vector<int> dis(n);
	for(int i =0;i<n;i++){
		dis[i] = (a[(i+1)%n] - a[i]+k)%k;
		sum+=dis[i];
	}
	sort(dis.begin(),dis.end());
	sum-=dis[n-1];
	cout << sum << endl;
}