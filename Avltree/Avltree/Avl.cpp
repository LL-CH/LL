#pragma once
template<class K, class V>

struct AVTreeNode{
	AVTreeNode<K, V>* _left;
	AVTreeNode<K, V>* _right;
	AVTreeNode<K, V>* _parent;

	int _bf;  //平衡因子

	pair<K, V> _kv;

	AVTreeNode(const pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};


template<class K, class V>

class AVLTree
{
	typedef AVTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv){
		// 1、先按搜索树的规则进行插入
		if (_root == nullptr){
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur){
			if (cur->_kv.first > kv.first){
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first <= kv.first){
				parent = cur;
				cur = cur->_right;
			}
			else{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first){
			parent->_right = cur;
			cur->_parent = parent;
		}
		else{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 2.更新平衡因子
		while (parent){
			if (cur == parent->_right)
				parent->_bf++;
			else
				parent->_bf--;

			if (parent->_bf == 0){
				// 说明parent所在的子树的高度不变，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1){
				// 说明parent所在的子树的高度变了，继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2){
				// parent所在的子树出现不平衡了，需要旋转处理。
				// 
			}
		}

		return true;
	}


	//左旋转
	void RotateL(Node* parent){

		Node* ret = parent->_right;
		Node* ret_l = ret->_left;

		parent->_right = ret_l;
		if (ret_l)
			ret_l->_parent = parent;

		ret->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = ret;

		// 1、原来parent是这颗树的根，现在ret是根
		// 2、parent为根的树只是整颗树中的子树，改变链接关系，那么ret要顶替他的位置
		if (_root == parent){
			_root = ret;
			ret->_parent = nullptr;
		}
		else{
			if (pparent->_left == parent)
				pparent->_left = ret;
			else
				pparent->_right = ret;

				ret->_parent = pparent;
		}

		parent->_bf = ret->_bf = 0;
	}

	//右旋转
	void RotateR(Node* parent)
	{
		Node* ret = parent->_left;
		Node* ret_r = ret->_right;

		parent->_left = ret_r;
		if (ret_r)
			ret_r->_parent = parent;

		ret->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = ret;

		if (_root == parent)
		{
			_root = ret;
			ret->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
				pparent->_left = ret;
			else
				pparent->_right = ret;

			ret->_parent = pparent;
		}

		ret->_bf = parent->_bf = 0;
	}

	//右左双旋
	void RotateRL(Node* parent){
		Node* ret_r = parent->_right;
		Node* ret_rl = ret_r->_left;

		int bf = ret_rl->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		//平衡因子调节
		if (bf == -1){
			parent->_bf = 0;
			ret_r->_bf = 1;
			ret_rl->_bf = 0;
		}
		else if (bf == 1){
			parent->_bf = -1;
			ret_r->_bf = 0;
			ret_rl->_bf = 0;
		}
		else if (bf == 0){
			parent->_bf = 0;
			ret_r->_bf = 0;
			ret_rl->_bf = 0;
		}
	}

	//左右双旋
	void RotateLR(Node* parent){
		Node* ret_l = parent->_left;
		Node* ret_lr = ret_l->_right;

		int bf = ret_lr->_bf;
		RotateL(ret_l);
		RotateR(parent);

		//判断平衡因子
		if (bf == -1){
			parent->_bf = 1;
			ret_l->_bf = 0;
			ret_lr->_bf = 0;
		}
		else if(bf == 1){
			parent->_bf = 0;
			ret_l->_bf = -1;
			ret_lr->_bf = 0;
		}
		else if (bf == 0){
			parent->_bf = 0;
			ret_l->_bf = 0;
			ret_lr->_bf = 0;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return lefeHeight > rightHeight ? lefeHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return abs(lefeHeight - rightHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}


private:
	Node* _root = nullptr;
};