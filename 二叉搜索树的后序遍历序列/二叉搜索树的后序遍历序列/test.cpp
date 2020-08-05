//��ʱ?????????
class Solution {
public:
	bool ispostorder(vector<int>& postorder, int start, int end){
		if (start >= end)
			return true;
		int root = postorder[end];//���ڵ�ֵ
		//������벿�֣��ȸ��ڵ�С
		int i = 0;
		while (i < end && postorder[i] < root)
			i++;
		//�����Ұ벿��,��i��ʼ����Ҫ����root
		for (int j = i; j < end; j++){
			if (postorder[j] < root)
				return false;
		}
		return ispostorder(postorder, 0, i - 1) && ispostorder(postorder, i, end - 1);
	}

	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.empty())
			return true;
		return ispostorder(postorder, 0, postorder.size() - 1);
	}
};

