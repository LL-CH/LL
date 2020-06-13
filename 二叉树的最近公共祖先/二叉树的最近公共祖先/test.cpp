
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool Find(TreeNode* root, TreeNode* x){
		if (root == NULL)
			return false;
		return root == x
			|| Find(root->left, x)
			|| Find(root->right, x);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		if (root == p || root == q)
			return root;

		bool pInleft, pInright, qInleft, qInright;  //ÅÐ¶ÏqºÍpÔÚ×ó×ÓÊ÷»¹ÊÇÓÒ×ÓÊ÷
		pInleft = Find(root->left, p);
		pInright = !pInleft;
		qInleft = Find(root->left, q);
		qInright = !qInleft;

		if ((pInleft && qInright) || (pInright && qInleft))
			return root;
		if (pInleft && qInleft)
			return lowestCommonAncestor(root->left, p, q);  //µÝ¹éÅÐ¶Ï
		if (pInright && qInright)
			return lowestCommonAncestor(root->right, p, q);
		return NULL;
	}
};