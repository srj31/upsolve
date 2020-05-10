#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){ return(b?gcd(b,a%b):a);}

int main(){
	int n;
	cin >> n;
	int a[n];
	int g=0;
	for(int i =0;i<n;i++){
		cin >> a[i];
		g = gcd(g,a[i]);
	}
	cout << "YES" << endl;

	if(g!=1){
		cout << "0" << endl;
	}
	else{
		int cnt = 0;
		for(int i =0;i<n-1;i++){
			if(a[i]&1){
				if(a[i+1]&1){
					cnt++;
					a[i] = 0;
					a[i+1] = 0;
				}
				else{
					cnt+=2;
					a[i] = 0;
				}
			}
		}
		if(a[n-1]&1){
			cnt+=2;
		}
		cout << cnt << endl;
	}
}