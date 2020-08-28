#pragma once
#include "HashTable.h"

using namespace OPEON_HASH;

namespace bit
{
	template<class K, class V, class Hash = OPEON_HASH::_Hash<K>>
	class unordered_map
	{
		struct MapKOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:

		typedef typename HashTable<K, pair<K, V>, MapKOfT, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		HashTable<K, pair<K, V>, MapKOfT, Hash> _ht;
	};

	void test_unordered_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "ÅÅÐò"));
		dict.insert(make_pair("left", "×ó±ß"));
		dict.insert(make_pair("string", "×Ö·û´®"));
		dict["left"] = "Ê£Óà";
		dict["end"] = "Î²²¿";

		//unordered_map<string, string>::iterator it = dict.begin();
		auto it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}
}