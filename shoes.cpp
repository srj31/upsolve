#include<bits/stdc++.h>
using namespace std;

long long count_swaps(vector<int> a){
	map<int,vector<int> > where;
	int n = a.size();
	int ans = 0;
	for(int i =0;i<n;i++){
		where[a[i]].push_back(i);
	}
	int done[n];
	memset(done,0,sizeof(done));
	for(int i =0;i<n/2;i++){
		if(done[i])continue;

		int size = a[i];
		int other = -size;
		int is1 = where[size][0];
		where[size].erase(where[size].begin());
		int is2 = where[other][0];
		where[other].erase(where[other].begin());
		ans += abs(is2-is1-1);
		if(size>0)
			ans++;
		done[is1]= 1;
		done[is2] = 1;

	}
	return ans;

}

int main(){
	// ifstream cin();
	// ofstream cout();

	int n;
	cin >> n;
	vector<int> a(2*n);
	for(int i =0;i<2*n;i++)
		cin >> a[i];
	int ans = count_swaps(a);
	cout << ans << endl;
}