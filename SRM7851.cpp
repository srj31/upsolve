
class EllysPalMulDiv2{
public:


	bool check(int x){
		int rev = 0;
		while(x>0){
			int d =x%10;
			rev = rev*10 + d;
			x/=10;
		}

		return rev == x;
	}
	int getMin(int X){
		int pos = 0;
		for(int i =1;i<=1000;i++){
			if(check(X*i)){
				return i;
			}
		}
		return -1;
	}
}