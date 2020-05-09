#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	int a,b,c;
	cin >> n >> a >> b >> c;
	string s[n];
	map<char,int> count;
	map<string,int> counts;
	for(int i=0;i<n;i++){
		cin >> s[i];
		count[s[i][0]]++;
		count[s[i][1]]++;
		counts[s[i]]++;
	}

	int abest = min(a,count['A']);
	int ab=0,ac = a;
	bool pos = false;
	//first completely finish As by ABs and ACs
	for(int i =0;i<=abest;i++){
		ab = i,ac = abest-i;
		// cout << ab << " " << ac << endl;
		if(ab>counts["AB"] || ac>counts["AC"]) continue;

		int ableft = counts["AB"]-ab;
		int acleft = counts["AC"]-ac;

		int bleft = b-ableft;
		int cleft = c-acleft;
		// cout << ableft << " " << acleft << " " << bleft << " " << cleft << endl;
		if(bleft<0 || cleft <0) continue;
		//so what is left now are BCs
		if(counts["BC"]<=bleft+cleft){
			pos =true;
			break;
		}

	}

	if(pos){
		cout << "Yes" << endl;
		int aba,abb,aca,acc,bcb,bcc;
		aba = ab;
		abb = counts["AB"]-aba;
		aca = ac;
		acc = counts["AC"] - aca;
		int bleft = b-abb;
		int cleft = c-acc;
		bcb = min(bleft,counts["BC"]);
		bcc = counts["BC"] - bleft;
		for(int i =0;i<n;i++){
			if(s[i]=="AB"){
				if(aba>0){
					cout <<"A" << endl;
					aba--;
				}
				else
					cout << "B" << endl;
			}

			if(s[i]=="BC"){
				if(bcb>0){
					cout << "B" << endl;
					bcb--;
				}
				else{
					cout << "C" << endl;
				}
			}
			if(s[i]=="AC"){
				if(aca>0){
					cout << "A" << endl;
					aca--;
				}
				else{
					cout << "C" << endl;
				}
			}
		}

	}
	else{
		cout << "No" << endl;
	}
}