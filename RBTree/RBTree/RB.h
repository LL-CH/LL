#pragma once
enum Color{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color color = RED)
	: _left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _data(data)
	, _color(color)
	{}

	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Color _color;
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_head = new Node;
		_head->_left = _head;
		_head->_right = _head;
	}

	bool Insert(const T& data)
	{
		// 按照二叉搜索树的性质插入新节点
		Node* & root = GetRoot();
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			root->_parent = _head;
			return true;
		}
		else
		{
			// 找待插入节点在二叉搜索树中的位置
			// 并保存其双亲节点
			Node* cur = root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (data < cur->_data)
					cur = cur->_left;
				else if (data > cur->_data)
					cur = cur->_right;
				else
					return false;
			}

			// 插入新节点
			cur = new Node(data);
			if (data < parent->_data)
				parent->_left = cur;
			else
				parent->_right = cur;

			cur->_parent = parent;

			// pCur新节点默认颜色：红色
			// 如果pParent的颜色是黑色的，满足红黑树性质
			// 如果pParent的颜色是红色的，违反了性质三--不能有连在一起的红色节点
			while (parent != _head && parent->_color == RED)
			{
				Node* gprent = parent->_parent;
				if (parent == gprent->_left)
				{
					Node* uncle = gprent->_right;
					// 叔叔节点存在且为红
					if (uncle && RED == uncle->_color)
					{
						// 情况一
						parent->_color = BLACK;
						uncle->_color = BLACK;
						gprent->_color = RED;
						cur = gprent;
						parent = cur->_parent;
					}
					else
					{
						// 叔叔节点不存在 || 叔叔节点存在 && 黑色
						if (cur == parent->_right)
						{
							// 情况三
							RotateL(parent);
							swap(cur, parent);
						}

						// 情况二：
						parent->_color = BLACK;
						gprent->_color = RED;
						RotateR(gprent);
					}
				}
				else
				{
					// 一二三的反情况
					Node* uncle = gprent->_left;
					if (uncle && RED == uncle->_color)
					{
						parent->_color = BLACK;
						uncle->_color = BLACK;
						gprent->_color = RED;
						cur = gprent;
						parent = cur->_parent;
					}
					else
					{
						// 叔叔节点不存在 || 存在且为黑
						if (cur == parent->_left)
						{
							// 情况三反情况
							RotateR(parent);
							swap(cur, parent);
						}

						// 情况二的反情况
						parent->_color = BLACK;
						gprent->_color = RED;
						RotateL(gprent);
					}
				}
			}
		}

		root->_color = BLACK;
		_head->_left = LeftMost();
		_head->_right = RightMost();
		return true;
	}

	Node*& GetRoot()
	{
		return _head->_parent;
	}

	void InOrder()
	{
		_InOrder(GetRoot());
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return _head;

		Node* cur = root;
		while (cur->_left)
			cur = cur->_left;

		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return _head;

		Node* cur = root;
		while (cur->_right)
			cur = cur->_right;

		return cur;
	}

	bool IsValidRBTRee()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		if (root->_color != BLACK)
		{
			cout << "违反性质一：根节点是黑色" << endl;
			return false;
		}

		// 获取一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->_color == BLACK)
				blackCount++;

			cur = cur->_left;
		}

		size_t pathBalck = 0;
		return _IsValidRBTRee(root, blackCount, pathBalck);
	}

private:
	bool _IsValidRBTRee(Node* root, size_t blackCount, size_t pathBlack)
	{
		if (nullptr == root)
			return true;

		if (root->_color == BLACK)
			pathBlack++;

		Node* parent = root->_parent;
		if (parent != _head &&
			RED == parent->_color && RED == root->_color)
		{
			cout << "违反性质3：不能存在连在一起的红色节点" << endl;
			return false;
		}

		// 叶子节点
		if (nullptr == root->_left && nullptr == root->_right)
		{
			if (pathBlack != blackCount)
			{
				cout << "违反性质4：每条路径中黑色节点个数均相同" << endl;
				return false;
			}
		}

		return _IsValidRBTRee(root->_left, blackCount, pathBlack) &&
			_IsValidRBTRee(root->_right, blackCount, pathBlack);
	}

	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_left);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_right);
		}
	}
	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_right;
		Node* pSubRL = pSubR->_left;

		pParent->_right = pSubRL;
		if (pSubRL)
			pSubRL->_parent = pParent;

		pSubR->_left = pParent;
		Node* pPParent = pParent->_parent;
		pSubR->_parent = pPParent;
		pParent->_parent = pSubR;

		if (pPParent == _head)
			_head->_parent = pSubR;
		else
		{
			if (pParent == pPParent->_left)
				pPParent->_left = pSubR;
			else
				pPParent->_right = pSubR;
		}
	}

	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_left;
		Node* pSubLR = pSubL->_right;

		pParent->_left = pSubLR;
		if (pSubLR)
			pSubLR->_parent = pParent;

		pSubL->_right = pParent;

		Node* pPParent = pParent->_parent;
		pParent->_parent = pSubL;
		pSubL->_parent = pPParent;

		if (pPParent == _head)
			_head->_parent = pSubL;
		else
		{
			if (pParent == pPParent->_left)
				pPParent->_left = pSubL;
			else
				pPParent->_right = pSubL;
		}
	}
private:
	Node* _head;
};
