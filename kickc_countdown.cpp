#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	int task = 1;
	while(task<=t){
		int n,k;
		cin >> n >> k;
		int a[n];
		for(int i =0;i<n;i++)
			cin >> a[i];
		int count=0;
		int check = k;
		for(int i = 0;i<n;i++){
			if(a[i]==check){
				check--;
			}
			else{
				if(a[i]==k)
					check = k-1;
				else
					check = k;
			}

			if(check==0){
				count++;
				check = k;
			}
		}

		cout << "Case #" << task << ": " << count << endl;
		task++;
		}

}