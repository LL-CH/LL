//超时?????????
class Solution {
public:
	bool ispostorder(vector<int>& postorder, int start, int end){
		if (start >= end)
			return true;
		int root = postorder[end];//根节点值
		//遍历左半部分，比根节点小
		int i = 0;
		while (i < end && postorder[i] < root)
			i++;
		//遍历右半部分,从i开始，都要大于root
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

