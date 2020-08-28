#pragma once
#include <string>
#include <vector>
//#include "Common1.h"

using namespace std;


namespace LL_Hash
{
	//��ϣ����
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

	//�ڵ㶨��
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

	// ������ʵ�ֵĹ�ϣͰ��key��Ψһ��
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

		// ��ϣͰ�е�Ԫ�ز����ظ�
		Node* Insert(const V& data)
		{
			// 0. ����Ƿ���Ҫ����
			CheckCapacity();

			// 1. ͨ����ϣ��������data���ڵ�Ͱ��
			size_t bucketNo = HashFunc(data);

			// 2. ����Ԫ���Ƿ���bucketNoͰ��
			//    ���ʣ�����������Ƿ����data�Ľڵ�
			Node* pCur = _table[bucketNo];
			while (pCur)
			{
				if (pCur->_data == data)
					return nullptr;

				pCur = pCur->_pNext;
			}

			// �����½ڵ�
			pCur = new Node(data);
			pCur->_pNext = _table[bucketNo];
			_table[bucketNo] = pCur;
			++_size;
			return pCur;
		}

		// ɾ����ϣͰ��Ϊdata��Ԫ��(data�����ظ�)
		bool Erase(const V& data)
		{
			size_t bucketNo = HashFunc(data);
			Node* pCur = _table[bucketNo];
			Node* pPre = nullptr;

			while (pCur)
			{
				if (data == pCur->_data)
				{
					// ɾ��
					if (_table[bucketNo] == pCur)
					{
						// ɾ����һ���ڵ�
						_table[bucketNo] = pCur->_pNext;
					}
					else
					{
						// ɾ���Ĳ��ǵ�һ���ڵ�
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

				// ɾ��i��Ͱ����Ӧ�����е����нڵ�
				while (pCur)
				{
					// ����ͷɾ
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

				// ���ɹ�ϣͰ�е�Ԫ�����¹�ϣͰ�н��а���
				// �������оɹ�ϣͰ�е�Ԫ��
				for (size_t i = 0; i < _table.capacity(); ++i)
				{
					Node* pCur = _table[i];
					while (pCur)
					{
						ht.Insert(pCur->_data); // new �ڵ�
						pCur = pCur->_pNext;
					}
				}

				Swap(ht);

				Self ht(GetNextPrime(_size));

				// ���ɹ�ϣͰ�еĽڵ�ֱ�����¹�ϣͰ�а���
				for (size_t i = 0; i < _table.capacity(); ++i)
				{
					Node* pCur = _table[i];
					while (pCur)
					{
						// ��pCur�ڵ�Ӿɹ�ϣͰ���Ƶ��¹�ϣͰ
						// 1. ��pCur�ڵ�Ӿ�������ɾ��
						_table[i] = pCur->_pNext;

						// 2. ��pCur�ڵ���뵽��������
						size_t bucketNo = ht.HashFunc(pCur->_data);

						// 3. ����ڵ�--->ͷ��
						pCur->_pNext = ht._table[bucketNo];
						ht._table[bucketNo] = pCur;
					}
				}

				this->Swap(ht);
			}
		}

	private:
		vector<Node*> _table;
		size_t _size;      // ��ϣ������ЧԪ�صĸ���
	};
}
