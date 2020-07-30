#pragma once
#include<iostream>

using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class ValueType>
//构造红黑树结点
struct RBTreeNode
{
	//ValueType,如果是map，则为pair<K,V>；如果是set，则为k
	ValueType _data;
	RBTreeNode<ValueType>* _left;
	RBTreeNode<ValueType>* _right;
	RBTreeNode<ValueType>* _parent;
	Color _color;

	RBTreeNode(const ValueType& data)
		: _data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _color(RED)
	{}
};

//红黑树的迭代器
template<class ValueType>
class RBTreeIterator
{
	typedef RBTreeNode<ValueType> Node;
	typedef RBTreeIterator<ValueType> self;
public:
	RBTreeIterator(Node* node)
		:_node(node)
	{}
	RBTreeIterator(const self& node)
		:_node(node._node)
	{}
	ValueType& operator*()
	{
		return _node->_data;
	}
	ValueType* operator->()
	{
		return &_node->_data;
	}
	self& operator==(const self& node)
	{
		return _node == node->_node;
	}
	bool operator!=(const self& node)
	{
		return _node != node._node;
	}
	self& operator++()
	{
		if (_node->_right)
		{
			Node* subR = _node->_right;
			while (subR->_left)
			{
				subR = subR->_left;
			}
			_node = subR;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	self& operator--()
	{
		if (_node->_left)
		{
			Node* subL = _node->_left;
			while (subL->_right)
			{
				subL = subL->_right;
			}
			_node = subL;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
private:
	Node* _node;//迭代器本质上是结点的指针
};

template<class K, class V, class KeyOfValue>
class RBTree
{
	typedef V ValueType;
	typedef RBTreeNode<ValueType> Node;
public:
	typedef RBTreeIterator<ValueType> Iterator;
	RBTree()
		:_root(nullptr)
	{}

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return Iterator(cur);
	}

	Iterator End()
	{
		return Iterator(nullptr);
	}

	pair<Iterator, bool> Insert(const ValueType& data)
	{
		if (nullptr == _root)
		{
			_root = new Node(data);
			_root->_color = BLACK;
			return make_pair(Iterator(_root), true);
		}
		KeyOfValue keyofvalue;
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			if (keyofvalue(data) < keyofvalue(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (keyofvalue(data) > keyofvalue(cur->_data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(Iterator(cur), false);
			}
		}
		cur = new Node(data);
		if (keyofvalue(data) < keyofvalue(parent->_data))
		{
			cur->_parent = parent;
			parent->_left = cur;
		}
		else
		{
			cur->_parent = parent;
			parent->_right = cur;
		}
		Node* newnode = cur;
		while (parent && RED == parent->_color)
		{
			//此时grandfather一定存在，因为parent存在，且颜色不是黑色，则parent一定不是根
			Node* gparent = parent->_parent;
			//parent在左侧的情况
			if (parent == gparent->_left)
			{
				Node* uncle = gparent->_right;
				if (uncle && RED == uncle->_color)
				{
					//叔叔结点存在且为红色
					parent->_color = uncle->_color = BLACK;
					gparent->_color = RED;
					cur = gparent;
					parent = cur->_parent;
				}
				else
				{
					//叔叔结点不存在，或叔叔结点存在且为黑色
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					gparent->_color = RED;
					parent->_color = BLACK;
					RotateR(gparent);
					break;
				}
			}
			//parent在右侧的情况
			else
			{
				Node* uncle = gparent->_left;
				if (uncle && RED == uncle->_color)
				{
					parent->_color = uncle->_color = BLACK;
					gparent->_color = RED;
					cur = gparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}
					RotateL(gparent);
					gparent->_color = RED;
					parent->_color = BLACK;
					break;
				}
			}
		}
		++_size;
		_root->_color = BLACK;
		return make_pair(Iterator(newnode), true);
	}
	Iterator Find(const K& key)
	{
		KeyOfValue keyofvalue;
		Node* cur = _root;
		while (cur)
		{
			if (keyofvalue(key) < keyofvalue(cur->_data))
			{
				cur = cur->_left;
			}
			else if (keyofvalue(key) > keyofvalue(cur->_data))
			{
				cur = cur->_right;
			}
			else
			{
				return Iterator(cur);
			}
		}
		return Iterator(nullptr);
	}
	size_t Size()const
	{
		return _size;
	}
	bool Empty()const
	{
		return 0 == _size;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* gparent = parent->_parent;
		parent->_parent = subR;
		if (parent == _root)
		{
			_root = subR;
		}
		else
		{
			if (gparent->_left == parent)
			{
				gparent->_left = subR;
			}
			else
			{
				gparent->_right = subR;
			}
		}
		subR->_parent = gparent;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		Node* gparent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (gparent->_left == parent)
			{
				gparent->_left = subL;
			}
			else
			{
				gparent->_right = subL;
			}
		}
		subL->_parent = gparent;
	}

private:
	Node* _root;
	size_t _size;
};
