#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n;
	cin >> n;
	long long int a,b;
	cin >> a >> b;
	long long int ans = n;
	if(a%2 == b%2){
		ans = (b-a)/2;
	}
	else{
		long long int to_1 = (a-1)+(b-a+1)/2;
		long long int to_n = (n-b)+(b-a+1)/2;
		ans = min(to_1,to_n);
	}
	cout << ans << endl;
}