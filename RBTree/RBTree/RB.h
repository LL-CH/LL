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
		// ���ն��������������ʲ����½ڵ�
		Node* & root = GetRoot();
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			root->_parent = _head;
			return true;
		}
		else
		{
			// �Ҵ�����ڵ��ڶ����������е�λ��
			// ��������˫�׽ڵ�
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

			// �����½ڵ�
			cur = new Node(data);
			if (data < parent->_data)
				parent->_left = cur;
			else
				parent->_right = cur;

			cur->_parent = parent;

			// pCur�½ڵ�Ĭ����ɫ����ɫ
			// ���pParent����ɫ�Ǻ�ɫ�ģ�������������
			// ���pParent����ɫ�Ǻ�ɫ�ģ�Υ����������--����������һ��ĺ�ɫ�ڵ�
			while (parent != _head && parent->_color == RED)
			{
				Node* gprent = parent->_parent;
				if (parent == gprent->_left)
				{
					Node* uncle = gprent->_right;
					// ����ڵ������Ϊ��
					if (uncle && RED == uncle->_color)
					{
						// ���һ
						parent->_color = BLACK;
						uncle->_color = BLACK;
						gprent->_color = RED;
						cur = gprent;
						parent = cur->_parent;
					}
					else
					{
						// ����ڵ㲻���� || ����ڵ���� && ��ɫ
						if (cur == parent->_right)
						{
							// �����
							RotateL(parent);
							swap(cur, parent);
						}

						// �������
						parent->_color = BLACK;
						gprent->_color = RED;
						RotateR(gprent);
					}
				}
				else
				{
					// һ�����ķ����
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
						// ����ڵ㲻���� || ������Ϊ��
						if (cur == parent->_left)
						{
							// ����������
							RotateR(parent);
							swap(cur, parent);
						}

						// ������ķ����
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
			cout << "Υ������һ�����ڵ��Ǻ�ɫ" << endl;
			return false;
		}

		// ��ȡһ��·���к�ɫ�ڵ�ĸ���
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
			cout << "Υ������3�����ܴ�������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		// Ҷ�ӽڵ�
		if (nullptr == root->_left && nullptr == root->_right)
		{
			if (pathBlack != blackCount)
			{
				cout << "Υ������4��ÿ��·���к�ɫ�ڵ��������ͬ" << endl;
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
