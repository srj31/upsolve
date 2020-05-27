#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	int cur = 0;
	stack<int>bal;
	stack<int>nobal;
	for(int i =0;i<n;i++){
		if(s[i]==')'){
			if(bal.size()==0)
				nobal.push(i);
			else{
				bal.pop();
			}
		}
		else{
			if(nobal.size()==0)
				bal.push(i);
			else{
				if(nobal.size()==1){
					int idx= nobal.top();
					ans+=(i-idx+1);
				}
				nobal.pop();				
			}
		}
		// cout << ans << endl;
	}
	if(bal.size()>0 || nobal.size()>0) ans=-1;
	cout << ans << endl;
}