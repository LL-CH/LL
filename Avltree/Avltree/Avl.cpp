#pragma once
template<class K, class V>

struct AVTreeNode{
	AVTreeNode<K, V>* _left;
	AVTreeNode<K, V>* _right;
	AVTreeNode<K, V>* _parent;

	int _bf;  //ƽ������

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
		// 1���Ȱ��������Ĺ�����в���
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

		// 2.����ƽ������
		while (parent){
			if (cur == parent->_right)
				parent->_bf++;
			else
				parent->_bf--;

			if (parent->_bf == 0){
				// ˵��parent���ڵ������ĸ߶Ȳ��䣬���½���
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1){
				// ˵��parent���ڵ������ĸ߶ȱ��ˣ��������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2){
				// parent���ڵ��������ֲ�ƽ���ˣ���Ҫ��ת����
				// 
			}
		}

		return true;
	}


	//����ת
	void RotateL(Node* parent){

		Node* ret = parent->_right;
		Node* ret_l = ret->_left;

		parent->_right = ret_l;
		if (ret_l)
			ret_l->_parent = parent;

		ret->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = ret;

		// 1��ԭ��parent��������ĸ�������ret�Ǹ�
		// 2��parentΪ������ֻ���������е��������ı����ӹ�ϵ����ôretҪ��������λ��
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

	//����ת
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

	//����˫��
	void RotateRL(Node* parent){
		Node* ret_r = parent->_right;
		Node* ret_rl = ret_r->_left;

		int bf = ret_rl->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		//ƽ�����ӵ���
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

	//����˫��
	void RotateLR(Node* parent){
		Node* ret_l = parent->_left;
		Node* ret_lr = ret_l->_right;

		int bf = ret_lr->_bf;
		RotateL(ret_l);
		RotateR(parent);

		//�ж�ƽ������
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