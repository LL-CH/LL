
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		vector<int> v;
		if (root == nullptr)
			return v;
		queue<TreeNode*> q;
		//把节点放入队列中
		q.push(root);
		while (!q.empty()){
			//从队列头开始取值
			TreeNode* p = q.front();
			q.pop();
			v.push_back(p->val);
			//左不为空
			if (p->left)
				q.push(p->left);
			//右不为空
			if (p->right)
				q.push(p->right);
		}

		return v;
	}
};

//将打印结果分层输出
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		if (root == nullptr)
			return vv;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()){
			vector<int> v;
			int num = q.size();
			for (int i = 0; i < num; i++){
				TreeNode* p = q.front();
				q.pop();
				v.push_back(p->val);
				if (p->left)
					q.push(p->left);
				if (p->right)
					q.push(p->right);
			}
			vv.push_back(v);
		}
		return vv;
	}
};


//按照之字形分层打印结果
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		if (root == nullptr)
			return vv;
		stack<TreeNode*> st;//保存要遍历的节点
		queue<TreeNode*> q;
		st.push(root);
		//dir=1,左先入栈，dir=2，右先入栈
		int dir = 1;
		while (!st.empty()){
			vector<int> v;
			int size = st.size();
			for (int i = 0; i < size; i++){
				TreeNode* cur = st.top();
				st.pop();
				v.push_back(cur->val);
				TreeNode* first = (dir == 1) ? cur->left : cur->right;
				TreeNode* second = (dir == 1) ? cur->right : cur->left;
				//将下一次的访问顺序放入q中
				if (first)
					q.push(first);
				if (second)
					q.push(second);
			}
			//将本层结果入数组
			vv.push_back(v);
			//将下一层节点入栈，进行逆序
			while (!q.empty()){
				st.push(q.front());
				q.pop();
			}
			//遍历一层后，更改入栈顺序
			dir = (dir == 1) ? 2 : 1;
		}
		return vv;
	}
};