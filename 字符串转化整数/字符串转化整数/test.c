int myAtoi(char * str){
	int i = 0, code = 0;
	long result = 0;
	while (str[i] == ' '){
		i++;
	}
	if (str[i] == '-'){
		if (str[i + 1] == '+')
			return 0;
		else{
			i++;
			code = 1;
		}
	}
	if (str[i] == '+'){
		i++;
	}

	while (str[i] >= '0'&&str[i] <= '9'){
		result = result * 10 + str[i++] - '0';
		if (result>INT_MAX){
			if (code = 1){
				result = INT_MIN;
				break;
			}
			else{
				result = INT_MAX;
				break;

			}
		}
	}
	if (code == 1){
		result = -result;
	}
	if (result == INT_MAX){
		result -= 1;
	}
	return result;
}



/*int myAtoi(char* str) {
    int result = 0, code = 1;
    for(; *str == ' '; str++);
    if(*str == '+')
    {
        code = 1;
        str++;
    }
    else if(*str == '-')
    {
        code = -1;
        str++;
    }
    for(; *str >= '0' && *str <= '9'; str++)
    {
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && *str > '7'))
        {
            return (code == -1)? INT_MIN: INT_MAX;
        }
        result = result * 10 + (*str - '0');
    }
    return result * code;
	}*/