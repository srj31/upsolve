#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[n-1];
	for(int i =0;i<n-1;i++)
		a[i] = abs(s[i]-s[i+1]);

	int cnt[3];
	memset(cnt,0,sizeof(cnt));
	for(int i =0;i<n-1;i++)
		cnt[a[i]]++;
	int to_check = 1;
	if(cnt[1]==0){
		to_check = 2;
		for(int i =0;i<n-1;i++)
			a[i]>>=1;
	}

	int res = 0;
	for(int i =0;i<n-1;i++){
		if(((n-2)&i) == i) // applying lucas theorem for mod 2
			res^=a[i];
	}
	// cout << res << to_check << endl;
	cout << (res%2)*to_check << endl;
}