#include<bits/stdc++.h>
using namespace std;
const int mxn = 305;

double p[mxn][mxn][mxn];
double ev[mxn][mxn][mxn];
int main(){
	int n;
	cin >> n;
	map<int,int> cnt;
	for(int i =0;i<n;i++){
		int a;
		cin >> a;
		cnt[a]++;
	}

	p[cnt[1]][cnt[2]][cnt[3]] = 1;

	for(int c =n;c>=0;c--){
		for(int b= n;b>=0;b--){
			for(int a = n;a>=0;a--){

				if(a==0 && b ==0 && c ==0)
					continue;

				if(a+b+c>n)continue;

				double p_waste = 1.0*(n-(a+b+c))/n; // the probability that I cant move from the current state
				double ev_waste = p_waste/(1-p_waste)+1; // expected number of moves required to move from the current state

				ev[a][b][c]+=ev_waste*p[a][b][c]; // The number of moves till I change --> add all the move wasted then +1 since a valid transformation is chosen
				if(a!=0){
					double pa = 1.0*a/(a+b+c);
					p[a-1][b][c] += p[a][b][c]*pa;
					ev[a-1][b][c] += ev[a][b][c]*pa;
				}
				if(b!=0){
					double pb=1.0*b/(a+b+c);
					p[a+1][b-1][c] += p[a][b][c]*pb;
					ev[a+1][b-1][c] +=ev[a][b][c]*pb;
				}
				if(c!=0){
					double pc = 1.0*c/(a+b+c);
					p[a][b+1][c-1]+=p[a][b][c]*pc;
					ev[a][b+1][c-1] +=ev[a][b][c]*pc;
				}
			}
		}
	}

	cout << fixed << setprecision(12) << ev[0][0][0] << endl;
}