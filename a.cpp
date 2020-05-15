#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> ans;
		int deg = 0;
		while(n>0){
			int d = n%10;
			ans.push_back(d*pow(10,deg));
			deg++;
			n/=10;
		}
		cout << ans.size() << endl;
		for(auto e:ans){
			cout << e << " ";
		}
		cout << endl;
	}
}