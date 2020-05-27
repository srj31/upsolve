#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e3+10;
struct pt{
	int r,c;
};

bool vis[mxn][mxn];
pt matrix[mxn][mxn];
int dx[4] = {-1,0,0,1} , dy[4] = {0,-1,1,0};
string dir = "DRLU";
// int dirv[4] = {0,1,2,3};
int n;

bool pos(int x,int y){
	if(x<1 || x >n) return false;
	if(y<1 || y > n) return false;
	return true;
}
string ans[mxn];
void dfs(int i, int j , char c){
	ans[i][j] = c;
	vis[i][j] = 1;
	for(int x = 0;x<4;x++){
		int nx = i+dx[x];
		int ny = j+dy[x];
		if(pos(nx,ny)){
			if(!vis[nx][ny] && matrix[i][j].r == matrix[nx][ny].r && matrix[i][j].c == matrix[nx][ny].c){
				dfs(nx,ny,dir[x]);
			}
		}
	}
}
int main(){
	// int n;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	// pt matrix[n+1][n+1];

	for(int i=1;i<=n;i++){
		ans[i]="";
		for(int j =1;j<=n;j++){
			ans[i]+=".";
		}
	}
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			int x,y;
			cin >> x >> y;
			matrix[i][j].r = x;
			matrix[i][j].c = y;
		}
	}

	int pos1 = 1;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			if(!vis[i][j] && matrix[i][j].r == i && matrix[i][j].c == j){
				dfs(i,j, 'X');
			}
			if(!vis[i][j] && matrix[i][j].r == -1){
				dfs(i,j,'A');
				//check for neightbors and reverse the direction
				for(int x= 0;x<4;x++){
					int nx = i+dx[x];
					int ny = j+dy[x];
					if(pos(nx,ny) && matrix[nx][ny].r == -1){
						char c = ans[nx][ny];
						if(c=='R' && x ==1)
							ans[i][j] = 'L';
						else if(c=='D' && x == 0)
							ans[i][j] = 'U';
						else if(c=='U' && x == 3)
							ans[i][j] = 'D';
						else if(c=='L' && x == 2)
							ans[i][j] = 'R'; 
					}
				}
				if(ans[i][j]=='A'){
					pos1&=0;
					cout << "INVALID" << endl;return 0;
				}
			}
		}
	}
	// cout << "VALID" << endl;
	// 	for(int i =1;i<=n;i++){
	// 		for(int j = 1;j<=n;j++){
	// 			cout << ans[i][j];
	// 		}cout << endl;
	// 	}
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			if(!vis[i][j]) pos1&=0;
		}
	}
	if(!pos1){
		cout<< "INVALID" << endl;
	}
	else{
		cout << "VALID" << endl;
		for(int i =1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				cout << ans[i][j];
			}cout << endl;
		}
	}
}