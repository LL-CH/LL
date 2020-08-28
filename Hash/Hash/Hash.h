#pragma once
#include <string>
#include <vector>
//#include "Common1.h"

using namespace std;


namespace LL_Hash
{
	//哈希函数
	template<class T>
	class HashFunc
	{
	public:
		size_t operator()(const T& val)
		{
			return val;
		}
	};

	template<>
	class HashFunc<string>
	{
	public:
		size_t operator()(const string& s)
		{
			const char* str = s.c_str();
			unsigned int seed = 131; // 31 131 1313 13131 131313
			unsigned int hash = 0;
			while (*str)
			{
				hash = hash * seed + (*str++);
			}

			return hash;
		}
	};

	//节点定义
	template<class V>
	struct HashBucketNode
	{
		HashBucketNode(const V& data)
		: _pNext(nullptr)
		, _data(data)
		{}

		HashBucketNode<V>* _pNext;
		V _data;
	};

	// 本文所实现的哈希桶中key是唯一的
	template<class V, class HF = HashFunc<V>>
	class HashBucket
	{
		typedef HashBucketNode<V> Node;
		typedef Node* PNode;

		typedef HashBucket<V, HF> Self;

	public:
		HashBucket(size_t capacity)
			: _table(GetNextPrime(capacity))
			, _size(0)
		{}

		~HashBucket()
		{
			Clear();
		}

		// 哈希桶中的元素不能重复
		Node* Insert(const V& data)
		{
			// 0. 检测是否需要扩容
			CheckCapacity();

			// 1. 通过哈希函数计算data所在的桶号
			size_t bucketNo = HashFunc(data);

			// 2. 检测该元素是否在bucketNo桶中
			//    本质：检测链表中是否存在data的节点
			Node* pCur = _table[bucketNo];
			while (pCur)
			{
				if (pCur->_data == data)
					return nullptr;

				pCur = pCur->_pNext;
			}

			// 插入新节点
			pCur = new Node(data);
			pCur->_pNext = _table[bucketNo];
			_table[bucketNo] = pCur;
			++_size;
			return pCur;
		}

		// 删除哈希桶中为data的元素(data不会重复)
		bool Erase(const V& data)
		{
			size_t bucketNo = HashFunc(data);
			Node* pCur = _table[bucketNo];
			Node* pPre = nullptr;

			while (pCur)
			{
				if (data == pCur->_data)
				{
					// 删除
					if (_table[bucketNo] == pCur)
					{
						// 删除第一个节点
						_table[bucketNo] = pCur->_pNext;
					}
					else
					{
						// 删除的不是第一个节点
						pPre->_pNext = pCur->_pNext;
					}

					delete pCur;
					--_size;
					return true;
				}

				pPre = pCur;
				pCur = pCur->_pNext;
			}

			return false;
		}

		Node* Find(const V& data)
		{
			size_t bucketNo = HashFunc(data);
			Node* pCur = _table[bucketNo];
			while (pCur)
			{
				if (data == pCur->_data)
					return pCur;

				pCur = pCur->_pNext;
			}

			return nullptr;
		}

		size_t Size()const
		{
			return _size;
		}

		bool Empty()const
		{
			return 0 == _size;
		}

		void Clear()
		{
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* pCur = _table[i];

				// 删除i号桶所对应链表中的所有节点
				while (pCur)
				{
					// 采用头删
					_table[i] = pCur->_pNext;
					delete pCur;
					pCur = _table[i];
				}
			}

			_size = 0;
		}

		size_t BucketCount()const
		{
			return _table.capacity();
		}

		void Swap(Self& ht)
		{
			_table.swap(ht._table);
			swap(_size, ht._size);
		}

	private:
		size_t HashFunc(const V& data)
		{
			return HF()(data) % _table.capacity();
		}

		void CheckCapacity()
		{
			if (_size == _table.capacity())
			{

				HashBucket<T> ht(_size * 2);

				// 将旧哈希桶中的元素向新哈希桶中进行搬移
				// 搬移所有旧哈希桶中的元素
				for (size_t i = 0; i < _table.capacity(); ++i)
				{
					Node* pCur = _table[i];
					while (pCur)
					{
						ht.Insert(pCur->_data); // new 节点
						pCur = pCur->_pNext;
					}
				}

				Swap(ht);

				Self ht(GetNextPrime(_size));

				// 将旧哈希桶中的节点直接向新哈希桶中搬移
				for (size_t i = 0; i < _table.capacity(); ++i)
				{
					Node* pCur = _table[i];
					while (pCur)
					{
						// 将pCur节点从旧哈希桶搬移到新哈希桶
						// 1. 将pCur节点从旧链表中删除
						_table[i] = pCur->_pNext;

						// 2. 将pCur节点插入到新链表中
						size_t bucketNo = ht.HashFunc(pCur->_data);

						// 3. 插入节点--->头插
						pCur->_pNext = ht._table[bucketNo];
						ht._table[bucketNo] = pCur;
					}
				}

				this->Swap(ht);
			}
		}

	private:
		vector<Node*> _table;
		size_t _size;      // 哈希表中有效元素的个数
	};
}
