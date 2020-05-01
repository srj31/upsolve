#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void solve(){
	int n;
	cin >> n;
	string s[n];
	vector<vector<int> > idxs(4);
	map<int,int> count;
	set<string> cantrev;
	for(int i =0;i<n;i++){
		cin >> s[i];
		int l = s[i].length();
		int num = 0;
		if(s[i][0]=='1')
			num+=2;
		if(s[i][l-1]=='1')
			num+=1;
		string comp = "";

		for(int j=l-1;~j;j--){
			comp+=s[i][j];
		}
		// cout << comp << endl;
		cantrev.insert(comp);
		idxs[num].push_back(i);
		count[num]++;
	}

	if(count[1]==0 && count[2] == 0 && (count[0]>0 && count[3]>0)){
		cout << -1 << endl;return;
	}

	int changes=0;
	vector<int> ans;
	if(count[1]>(count[2]+1)){
		while(count[1]>count[2]+1){
			if(idxs[1].size()==0){
				cout << -1 << endl;return;
			}
			int i = *idxs[1].begin();
			// cout << i << " " << count[1] << " " << count[2] << endl;
			string torev = s[i];
			string rev = "";
			for(int j =torev.length()-1;~j;j--){
				rev+=torev[j];
			}
			int revpos = 1;
			if(cantrev.find(torev)!=cantrev.end()){
				revpos = 0;
			}
			// cout << rev << " " <<revpos <<  endl;

			if(revpos){
				count[1]--;
				count[2]++;
				ans.push_back(*idxs[1].begin());
			}
			idxs[1].erase(idxs[1].begin());
		}
	}
	else if(count[2]>(count[1]+1)){
		while(count[2]>count[1]+1){
			if(idxs[2].size()==0){
				cout << -1 << endl;return;
			}
			int i = *idxs[2].begin();
			// cout << i << endl;
			string torev = s[i];
			string rev = "";
			for(int j =torev.length()-1;~j;j--){
				rev+=torev[j];
			}
			int revpos = 1;
			if(cantrev.find(torev)!=cantrev.end()){
				revpos = 0;
			}
			if(revpos){
				count[2]--;
				count[1]++;
				ans.push_back(*idxs[2].begin());
			}
			idxs[2].erase(idxs[2].begin());
		}
	}

	cout << ans.size() << endl;
	for(int i =0;i<ans.size();i++){
		cout << ans[i]+1 << " ";
	}cout << endl;

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int t;cin >> t;while(t--)
		solve();
}