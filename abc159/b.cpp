#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	string rev = s;
	int n =s.length();
	reverse(rev.begin(),rev.end());
	if(s!=rev){
		cout << "No" << endl;return 0;
	}

	string s1 = s.substr(0,(n-1)/2);
	string s1rev =s1;
	reverse(s1rev.begin(),s1rev.end());
	if(s1!=s1rev){
		cout << "No" << endl;return 0;
	}

	string s2 = s.substr((n+3)/2-1,n/2);
	string s2rev = s2;
	reverse(s2rev.begin(),s2rev.end());
	if(s2!=s2rev){
		cout << "No" << endl;return 0;

	}
	cout << "Yes" << endl;
}