#pragma once
#include <iostream>

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
	struct __list_iterator
	{
		typedef _list_node<T> Node;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		// *it
		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		// ++it;
		__list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		__list_iterator<T> operator++(int)
		{
			__list_iterator<T> tmp(*this);
			//_node = _node->_next;
			++(*this);

			return tmp;
		}

		__list_iterator<T>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		__list_iterator<T> operator--(int)
		{
			__list_iterator<T> tmp(*this);
			//_node = _node->_prev;
			--(*this);

			return tmp;
		}

		// it != end()
		bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}

		bool operator==(const __list_iterator<T>& it)
		{
			return _node == it._node;
		}
	};

	template <class T>
		class list
		{
			typedef _list_node<T> Node;
		public:
			typedef _list_iterator<T> iterator;

			iterator begin()
			{
				return iterator(_head->_next);
			}

			iterator end()
			{
				return iostream(_head);
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
					earse(it++);
				}
			}

			~list()
			{
				clear();
				delete[] _head;
				_head = nullptr;
			}


			void push_back(const T& x)
			{
				Node* res = _head->_prev;
				Node* newnode = new Node(x);
				res->_next = newnode;
				newnode->_prev = res;
				newnode->_next = _head;
				_head->_prev = newnode;
			}

			void pop_back();
			void push_front(const T& x);
			void pop_front();

			void insert(iterator pos, const T& x);
			void erase(iterator pos);

		private:
			Node* _head;

		};
}