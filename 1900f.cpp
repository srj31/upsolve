#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long int ans = n*1LL*(n-1)/2;
	map<char,int> pos;
	pos['A'] = pos['B'] = -1;
	pos[s[0]] = 0;
	for(int i =1;i<n;i++){
		char shouldbe = s[i]^'A'^'B';
		if(s[i]==s[i-1]){
			//find the pos of the other
			if(pos[shouldbe]>-1)
				ans--;
		}
		else{
			ans -= i-pos[s[i]]-1;
		}
		pos[s[i]] = i;
	}
	cout << ans << endl;
}

int main(){
	// int t;
	// cin >> t;
	// while(t--)
		solve();
}