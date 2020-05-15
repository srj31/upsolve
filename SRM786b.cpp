#include<bits/stdc++.h>
using namespace std;

class SmallestRegular{
	public:


		vector <int> findLexSmallest(string S){
			vector<int> ans;
			int n =S.length();
			int count = 0;
			for(int i =0;i<n;i++){
				if(count==n/2)break;
				if(S[i]=='('){
					count++;
					continue;
				}


				int j = i;
				while(S[j]!='(')
					j++;

				int dist = j-i;
				int a = i - dist;
				int b = j-1;
				int c = j;
				ans.push_back(a);
				ans.push_back(b);
				ans.push_back(c);
				
				string newS="";
				for(int k = 0;k<a;k++)
					newS+=S[k];
				newS+=S[c];
				for(int k = a;k<c;k++)
					newS+=S[k];

				S = newS;
				count++;
			}

			return ans;
		}

};