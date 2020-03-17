#include<stdio.h>

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n){
	for (int i = 0; i < n - 1; i++){
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0){
			if (a[end]>tmp){
				a[end + 1] = a[end];
				--end;
			}
			else{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n){
	//gap>1  ‘§≈≈–Ú
	//gap=1  ≤Â»Î≈≈–Ú
	int gap = n;
	while (gap > 1){
		//º‰∏Ùgapµƒ‘§≈≈–Ú
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++){
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0){
				if (a[end]>tmp){
					a[end + gap] = a[end];
					end -= gap;
				}
				else{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n){
	int begin = 0, end = n - 1;
	while (begin < end){

	}
}