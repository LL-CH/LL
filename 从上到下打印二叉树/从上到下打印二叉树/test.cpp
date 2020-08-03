
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
		//�ѽڵ���������
		q.push(root);
		while (!q.empty()){
			//�Ӷ���ͷ��ʼȡֵ
			TreeNode* p = q.front();
			q.pop();
			v.push_back(p->val);
			//��Ϊ��
			if (p->left)
				q.push(p->left);
			//�Ҳ�Ϊ��
			if (p->right)
				q.push(p->right);
		}

		return v;
	}
};

//����ӡ����ֲ����
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


//����֮���ηֲ��ӡ���
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		if (root == nullptr)
			return vv;
		stack<TreeNode*> st;//����Ҫ�����Ľڵ�
		queue<TreeNode*> q;
		st.push(root);
		//dir=1,������ջ��dir=2��������ջ
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
				//����һ�εķ���˳�����q��
				if (first)
					q.push(first);
				if (second)
					q.push(second);
			}
			//��������������
			vv.push_back(v);
			//����һ��ڵ���ջ����������
			while (!q.empty()){
				st.push(q.front());
				q.pop();
			}
			//����һ��󣬸�����ջ˳��
			dir = (dir == 1) ? 2 : 1;
		}
		return vv;
	}
};