class EllysConjectureDiv2{

public:
	long long getSum(int L, int R){
		long long ans = 0;
		for(int i =L,i<=R;i++){
			if(i%3==0)
				ans+=6;
			else
				ans+=4;
		}
		return ans;
	}
};