class EllysNimDiv2
{

public:
	int getMin(vector <int> A){
		int ans = 0;
		int n = A.size();
		for(int i =0;i<n-1;i++){
			ans^=A[i];
		}
		if(ans^A[n-1]==0)
			return 0;
		else{
			int toadd = 
		}
	}
};