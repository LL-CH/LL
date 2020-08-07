#include<iostream>
#include<vector>

class  UnionFindSet{
public:
	// 初始时，将数组中元素全部设置为-1 
	UnionFindSet(int n)
		:_ufs(n,-1)
	{}

	// 给一个元素的编号，找到该元素所在集合的名称 
	int Findroot(int x){
		// 如果数组中存储的是负数，找到，否则一直继续 
		while(_ufs[x]>=0){
			x = _ufs[x];
		}
		return x;
	}

	//合并集合
	bool Union(int x1,int x2){
		int root1 = Findroot(x1);
		int root2 = Findroot(x2);

		//x1和x2在同一个集合
		if(root1==root2){
			return false;
		}
		//合并两个元素
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;

		return true;
	}

	// 数组中负数的个数，即为集合的个数
	 int Count(){
		int count = 0;
		for(auto e:_ufs){
			if (e < 0)
				count++;
		}
		return count;
	}


private:
	vector<int> _ufs;
};