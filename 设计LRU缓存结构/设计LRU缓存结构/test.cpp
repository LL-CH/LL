#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRU{
public:
	LRU(int capacity){
		_capacity = capacity;
	}


	void set(int key, int value){
		//bucunzai
		if (_map.find(key) == _map.end()){
			if (_lt.size() == _capacity){
				auto last = _lt.back();
				_map.erase(last.first);
				_lt.pop_back();
			}
			_lt.push_front(make_pair(key, value));
			_map[key] = _lt.begin();
		}
		else{
			_lt.erase(_map[key]);
			_lt.push_front(make_pair(key, value));
			_map[key] = _lt.begin();
		}
	}

	int get(int key){
		if (_map.find(key) == _map.end())
			return -1;
		else{
			pair<int, int> kv = *_map[key];
			_lt.erase(_map[key]);
			_lt.push_front(kv);

			_map[key] = _lt.begin();

			return kv.second;
		}
	}
private:
	int _capacity;
	list<pair<int, int>> _lt;
	unordered_map<int, list<pair<int, int>>::iterator> _map;
};

int main(){
	int n, k, opt, x, y;
	cin >> n >> k;
	LRU l(k);
	for (int i = 0; i < n; i++){
		cin >> opt;
		if (opt == 1){
			cin >> x >> y;
			l.set(x, y);
		}
		else if (opt == 2){
			cin >> x;
			int ret = l.get(x);
			cout << ret << endl;
		}
	}
	return 0;
}