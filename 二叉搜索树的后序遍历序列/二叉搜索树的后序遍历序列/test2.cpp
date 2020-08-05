//将数组翻转，则顺序为“根右左”，如果我们使用单调栈存储根节点和右子树，
//当遇到左子树时，左子树节点肯定比根节点和右子树小，依次出栈，并更新root节点。
//如果root节点小于即将入栈的元素，说明顺序错误，直接返回失败。

//备注：为了保证第一个节点入栈时的正确性，root节点初始化为INT_MAX.


class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.size() == 0){
			return true;
		}
		stack<int> q;
		int root = INT_MAX;
		for (int i = postorder.size() - 1; i >= 0; i--){
			if (postorder[i] > root){
				return false;
			}
			while (!q.empty() && q.top() > postorder[i]){
				root = q.top();
				q.pop();
			}
			q.push(postorder[i]);
		}
		return true;
	}
};