#include"RBTree.h"

namespace LL{
	template<class K>
	class MySet
	{
		typedef K ValueType;
		struct KeyOfValue
		{
			const K& operator()(const ValueType& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, ValueType, KeyOfValue>::Iterator Iterator;

		pair<Iterator, bool> Insert(const ValueType& key)
		{
			return tree.Insert(key);
		}
		Iterator Begin()
		{
			return tree.Begin();
		}
		Iterator End()
		{
			return tree.End();
		}
		Iterator Find(const K& key)
		{
			return tree.Find(key);
		}
		size_t Size()const
		{
			return tree.Size();
		}
	private:
		RBTree<K, ValueType, KeyOfValue> tree;
	};

	void TestMySet()
	{
		MySet<int> s;
		s.Insert(4);
		s.Insert(2);
		s.Insert(3);
		s.Insert(1);
		s.Insert(18);
		s.Insert(15);

		MySet<int>::Iterator it = s.Begin();
		while (it != s.End())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}