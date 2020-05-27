#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,w,k;
	cin >> h >> w >> k;
	string c[h];
	for(int i =0;i<h;i++)
		cin >> c[i];

	int ans = h*w+1;
	int pref[h+1][w+1];
	memset(pref,0,sizeof(pref));
	for(int i =1;i<=h;i++){
		for(int j =1;j<=w;j++){
			pref[i][j] = pref[i-1][j]+pref[i][j-1] - pref[i-1][j-1] + (c[i-1][j-1]=='1');
			// cout << pref[i][j] << " ";
		}
		// cout << endl;
	}
	for(int i =0;i<=(1<<(h-1));i++){
		//find where to cut horizontally first;
		int hs = i;
		vector<int> cuts;
		int hcut = 1;
		// int cnt1s=0;
		cuts.push_back(0);
		while(hs>0){
			if(hs&1)
				cuts.push_back(hcut);
			hcut++;
			hs>>=1;
		}
		int cur = cuts.size()-1;
		cuts.push_back(h);
		int j = 1;
		// int py =0,px = 0;
		int py = 0;
		// int req = 1;
		int good = 1;
		while(j<=w){
			// cout << j << " " << py <<" " << i <<  endl;
			for(int i =0;i<cuts.size()-1;i++){
				if(pref[cuts[i+1]][j]+pref[cuts[i]][py] - pref[cuts[i+1]][py]-pref[cuts[i]][j]>k){
					// need to stop the one before this j was the cut
					// if(j==3 && py==2){
					// 	cout <<pref[cuts[i+1]][j]<< " " << pref[cuts[i]][py]<< " "<<  pref[cuts[i+1]][py]<< " " << pref[cuts[i]][j]<< endl;
					// 	exit(0);
					// }
					cur++;
					j--;
					int olpy = py;
					py = j;
					if(py==olpy){
						good = 0;
					}
					break;
				}
			}
			if(!good)break;
			j++;
		}
		if(good)
		ans = min(cur,ans);
	}
	cout << ans << endl;
}