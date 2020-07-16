//错排问题。
//
//当n个编号元素放在n个编号位置，元素编号与位置编号各不对应的方法数用D(n)表示，那么D(n - 1)就表示n - 1个编号元素放在n - 1个编号位置，各不对应的方法数，其它类推.
//第一步，把第n个元素放在一个位置，比如位置k，一共有n - 1种方法；
//第二步，放编号为k的元素，这时有两种情况：⑴把它放到位置n，那么，对于剩下的n - 1个元素，由于第k个元素放到了位置n，剩下n - 2个元素就有D(n - 2)种方法；⑵第k个元素不把它放到位置n，这时，对于这n - 1个元素，有D(n - 1)种方法；
//综上得到
//D(n) = (n - 1)[D(n - 2) + D(n - 1)]
//特殊地，D(1) = 0, D(2) = 1.

#include<iostream>

using namespace std;

int main(){
	long res[21] = { 0, 0, 1, 2 };
	for (int i = 4; i < 21; i++){
		res[i] = (i - 1)*(res[i - 1] + res[i - 2]);
	}

	int n;
	while (cin >> n){
		cout << res[n] << endl;
	}
	return 0;
}