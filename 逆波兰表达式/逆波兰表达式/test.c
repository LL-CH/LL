int evalRPN(char ** tokens, int tokensSize){
	int top = 0;
	int *stack = (int *)malloc(sizeof(int)* tokensSize);
	int num1, num2;
	for (int i = 0; i < tokensSize; i++){
		if (tokens[i][1] == '\0' && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/')){
			num2 = stack[--top];
			num1 = stack[--top];
			switch (tokens[i][0]){
			case '-':
				stack[top++] = num1 - num2;
				break;
			case '+':
				stack[top++] = num1 + num2;
				break;
			case '*':
				stack[top++] = num1 * num2;
				break;
			case '/':
				stack[top++] = num1 / num2;
				break;
			default:
				break;
			}
		}
		else{
			stack[top++] = atoi(tokens[i]);
		}
	}

	return stack[--top];
}