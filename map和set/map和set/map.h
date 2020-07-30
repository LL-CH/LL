#include"RBTree.h"
#include<string>

namespace LL{

	template<class K, class V>
	class MyMap
	{
	public:
		typedef pair<K, V> ValueType;
		struct KeyOfValue
		{
			const K& operator()(const ValueType& kv)
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, ValueType, KeyOfValue>::Iterator Iterator;
		pair<Iterator, bool> Insert(const ValueType& v)
		{
			return tree.Insert(v);
		}
		V& operator[](const K& key)
		{
			pair<Iterator, bool> ret = tree.Insert(make_pair(key, V()));
			return ret.first->second;
		}
		Iterator Begin()
		{
			return tree.Begin();
		}
		Iterator End()
		{
			return tree.End();
		}

	private:
		RBTree<K, ValueType, KeyOfValue> tree;
	};

	void TestMyMap()
	{
		MyMap<string, string> dict;
		dict.Insert(make_pair("apple", "Æ»¹û"));
		dict.Insert(make_pair("water", "Ë®"));
		dict.Insert(make_pair("sister", "½ãÃÃ"));
		MyMap<string, string>::Iterator it = dict.Begin();
		/*while (it != dict.End())
		{
		cout << it->first << " ";
		++it;
		}
		cout << endl;*/
		dict["sister"] = "½ã½ã";
		it = dict.Begin();
		while (it != dict.End())
		{
			cout << it->first << " " << it->second << " ";
			++it;
		}
	}

}
	
