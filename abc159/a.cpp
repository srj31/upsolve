#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	long long int ans = 1LL *n *(n-1)/2 + 1LL * m*(m-1)/2;
	cout << ans << endl;
}