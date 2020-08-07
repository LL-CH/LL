#include<iostream>
#include<vector>

class  UnionFindSet{
public:
	// ��ʼʱ����������Ԫ��ȫ������Ϊ-1 
	UnionFindSet(int n)
		:_ufs(n,-1)
	{}

	// ��һ��Ԫ�صı�ţ��ҵ���Ԫ�����ڼ��ϵ����� 
	int Findroot(int x){
		// ��������д洢���Ǹ������ҵ�������һֱ���� 
		while(_ufs[x]>=0){
			x = _ufs[x];
		}
		return x;
	}

	//�ϲ�����
	bool Union(int x1,int x2){
		int root1 = Findroot(x1);
		int root2 = Findroot(x2);

		//x1��x2��ͬһ������
		if(root1==root2){
			return false;
		}
		//�ϲ�����Ԫ��
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;

		return true;
	}

	// �����и����ĸ�������Ϊ���ϵĸ���
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