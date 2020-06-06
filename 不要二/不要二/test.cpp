//w * h的方格行编号为0~h-1，网格的列编号为0~w-1。
//每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//欧几里得距离为:((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根，求能放多少蛋糕

#include<iostream> 

using namespace std;

int a[1000][1000] = { 0 };
int main()
{
	int w, h, res = 0;
	cin >> w >> h;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (a[i][j] == 0)
			{
				res++;
				if ((i + 2) < w)
					a[i + 2][j] = -1;
				if ((j + 2) < h)
					a[i][j + 2] = -1;
			}
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}