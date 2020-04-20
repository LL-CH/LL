class Sum{
public:
	Sum(){
		_sum += _n;
		++_n;
	}
	static void Init(){
		_n = 1;
		_sum = 0;
	}
	static int GetSum(){
		return _sum;
	}
private:
	static int _n;
	static int _sum;
};

int Sum::_n = 1;
int Sum::_sum = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		Sum::Init();
		Sum* p=new Sum[n]; //����n��
		//Sum a[n]; �汾����
		return Sum::GetSum();
	}
};