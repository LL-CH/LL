#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*char * reverseOnlyLetters(char * S){
	int left = 0;
	int right = strlen(S) - 1;
	while (left<right){
		if (((S[left])<'a' || (S[left])>'z') && (((S[left])<'A' || (S[left])>'Z'))){
			left++;
		}
		else if (((S[right])<'a' || (S[right])>'z') && (((S[right])<'A' || (S[right])>'Z'))){
			right--;
		}
		else{
			char temp = S[left];
			S[left] = S[right];
			S[right] = temp;
			left++;
			right--;
		}

	}
	return S;
}*/

void reverseOnlyLetters(char * S){
	int len = strlen(S);
	char *arr = malloc(sizeof(char)* len);
	int arr_index = 0;
	for (int i = len - 1; i >= 0; i--){
		if ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122)){
			arr[arr_index++] = S[i];
		}
	}
	arr_index = 0;
	for (int i = 0; i<len; i++){
		if ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122)){
			S[i] = arr[arr_index++];
		}
	}
}

int main(){
	char s[] = "ab-cd";
	reverseOnlyLetters(s);
	printf("%s\n", s);
	system("pause");
}