#include<bits/stdc++.h>
using namespace std;

class  CutTheCube{
	public:

		 int findWinner(int L, int B, int H){
		 	long long int val = L*B*H;
		 	if(val%2==0)
		 		return 1;
		 	else
		 		return 2;
		 }

};