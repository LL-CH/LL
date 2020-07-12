#include <iostream>
#include<set>
using namespace std;

int main(){
	int n, k;
	while (cin >> n){
		int num;
		set<int> s;
		for (int i = 0; i < n; i++){
			cin >> num;
			s.insert(num);
		}
		int i;
		cin >> k;
		set<int>::iterator it;
		for (it = s.begin(), i = 0; it != s.end() && i < k - 1; ++it, ++i){

		}
		cout << *it << endl;
	}
	return 0;
}