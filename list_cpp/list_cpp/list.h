#pragma once

#include <iostream>
#include<assert.h>

using namespace std;
namespace LL
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;

		_list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> My;
		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		// *it
		Ref& operator*()
		{
			return _node->_data;
		}

		Ptr* operator->()
		{
			return &_node->_data;
		}

		// ++it;
		My& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		My operator++(int)
		{
			My tmp(*this);
			//_node = _node->_next;
			++(*this);

			return tmp;
		}

		My& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		My operator--(int)
		{
			My tmp(*this);
			//_node = _node->_prev;
			--(*this);

			return tmp;
		}

		// it != end()
		bool operator!=(const My& it)
		{
			return _node != it._node;
		}

		bool operator==(const My& it)
		{
			return _node == it._node;
		}
	};

	template <class T>
		class list
		{
			typedef _list_node<T> Node;

		public:
			typedef _list_iterator<T, T&, T*>  iterator;
			typedef _list_iterator<T, const T&, const T*> const_iterator;

			iterator begin()
			{
				return iterator(_head->_next);
			}

			iterator end()
			{
				return iterator(_head);
			}

			const_iterator begin() const
			{
				return const_iterator(_head->_next);
			}

			const_iterator end() const
			{
				return const_iterator(_head);
			}

			//带头双向链表
			list()
			{
				_head = new Node;
				_head->_next = _head;
				_head->_prev = _head;
			}

			void clear()
			{
				iterator it = begin();
				while (it != end())
				{
					erase(it++);
				}
			}

			~list()
			{
				clear();
				delete[] _head;
				_head = nullptr;
			}

			list(const list<T>& l)
			{
				_head = new Node;
				_head->_next = _head;
				_head->_prev = _head;

				for (auto a : l)
				{
					push_back(a);
				}
			}

			list<T>& operator=(const list<T>& l)
			{
				if (this != &l)
				{
					clear();
					for (auto a : l)
					{
						push_back(a);
					}
				}
				return *this;
			}

			/*list<T>& operator=(const list<T>& l)
			{
			swap(_head, l._head);
			return *this;
			}*/

			void push_back(const T& x)
			{
				/*Node* res = _head->_prev;
				Node* newnode = new Node(x);
				res->_next = newnode;
				newnode->_prev = res;
				newnode->_next = _head;
				_head->_prev = newnode;*/

				insert(end(), x);
			}

			void pop_back()
			{
				erase(--end());

			}
			

			void push_front(const T& x)
			{
				insert(begin(), x);
			}

			void pop_front()
			{
				erase(begin());
			}

			void insert(iterator pos, const T& x)
			{
				Node* cur = pos._node;
				Node* prev = cur->_prev;
				Node* newnode = new Node(x);
				prev->_next = newnode;
				newnode->_prev = prev;
				newnode->_next = cur;
				cur->_prev = newnode;
			}

			void erase(iterator pos)
			{
				assert(pos != end());
				Node* cur = pos._node;
				Node* prev = cur->_prev;
				Node* next = cur->_next;
				prev->_next = next;
				next->_prev = prev;
				delete cur;
			}

		private:
			Node* _head;
		};

	
}